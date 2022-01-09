/**
 🍪 the_hyp0cr1t3
 🍪 09.01.2022 20:27:01
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

template <class T, bool ONE = true>
struct BIT {
    int N; vector<T> bit;
    BIT(int N): N(N), bit(N + 1) {}

    T query(int i) {
        T res = 0;
        for(i += !ONE; i; i -= i & -i)
            res += bit[i];
        return res;
    }

    void update(int i, T val) {
        for(i += !ONE; i <= N; i += i & -i)
            bit[i] += val;
    }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int LG = 18;

    int i, j, n, k; string s;
    cin >> n >> k >> s;
    vector<int> l(n), r(n);
    for(i = 0; i < n; i++)
        cin >> l[i] >> r[i], --l[i], --r[i];

    array<vector<int>, LG> anc;
    for(auto& x: anc) x.assign(n, -1);
    vector<int> tin(n), order, depth(n), sub(n, 1);
    order.reserve(n);

    Y([&, t = 0](auto dfs, int v, int p, int d) mutable -> void {
        tin[v] = t++;
        anc[0][v] = p; depth[v] = d;
        for(int z = 1; z < LG; z++)
            if(~anc[z - 1][v]) anc[z][v] = anc[z - 1][anc[z - 1][v]];
        if(~l[v])
            dfs(l[v], v, d + 1), sub[v] += sub[l[v]];
        order.push_back(v);
        if(~r[v])
            dfs(r[v], v, d + 1), sub[v] += sub[r[v]];
    })(0, -1, 0);

    BIT<int, 0> bit(n + 1);
    vector<int> taken(n);
    for(i = j = 0; i < n and k; i++) {
        while(j < n and s[order[j]] == s[order[i]]) j++;
        int v = order[i];
        if(taken[v]) continue;
        if(j == n or s[v] > s[order[j]]) {
            bit.update(tin[v], +1);
            bit.update(tin[v] + sub[v], -1);
        } else {
            if(bit.query(tin[v])) continue;
            for(int z = LG - 1; ~z; z--)
                if(~anc[z][v] and !taken[anc[z][v]])
                    v = anc[z][v];
            if(depth[order[i]] - depth[v] + 1 > k) continue;
            for(v = order[i]; ~v and !taken[v]; v = anc[0][v])
                taken[v] = true, k--;
        }
    }

    string ans;
    for(auto v: order) {
        ans += s[v];
        if(taken[v]) ans += s[v];
    }

    cout << ans;

} // ~W