/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 17:48:49
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

struct DSU {
    int n, components;
    vector<int> data, nxt;

    DSU(int n): n(n), components(n), data(n + 1, -1), nxt(n + 1) {
        iota(nxt.begin(), nxt.end(), 0);
    }

    int par(int x) {
        return data[x] < 0? x : data[x] = par(data[x]);
    }

    int alive(int x) {
        return nxt[par(x)];
    }

    int SZ(int x) {
        return -data[par(x)];
    }

    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; components--;
        nxt[x] = max(nxt[x], nxt[y]);
        return true;
    }

};

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 1 << 20;

    vector<int64_t> ans(N, -1);
    DSU dsu(2 * N);

    int i, q;
    cin >> q;
    while(q--) {
        int t; int64_t x;
        cin >> t >> x;
        if(t == 1) {
            int nxt = dsu.alive(x % N);
            ans[nxt % N] = x;
            dsu.merge(nxt, nxt + 1);
            if(nxt >= N)
                dsu.merge(nxt - N, nxt - N + 1);
        } else {
            cout << ans[x % N] << '\n';
        }
    }

} // ~W