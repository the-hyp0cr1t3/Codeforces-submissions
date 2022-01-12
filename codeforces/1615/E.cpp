/**
 🍪 the_hyp0cr1t3
 🍪 12.01.2022 15:06:21
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

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n, k;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<int> wcnt(n + 1), whites;
    int d = Y([&](auto dfs, int v, int p) -> int {
        int mx = 0;
        for(auto& x: g[v]) if(x ^ p) {
            int d = dfs(x, v);
            if(d > mx) swap(mx, d);
            wcnt[d]++;
        }
        return mx + 1;
    })(0, -1);
    wcnt[d]++;

    whites.reserve(n);
    for(i = n; i; i--)
        while(wcnt[i]--) whites.push_back(i);
    whites.resize(k);

    long long ans = -1e18;
    for(int r = 0, B = n; r <= k; r++) {
        if(r > 0) B -= whites[r - 1];
        int b = min(n / 2, B);
        ans = max(ans, 1LL * (n - r - b) * (r - b));
    }

    cout << ans;
} // ~W