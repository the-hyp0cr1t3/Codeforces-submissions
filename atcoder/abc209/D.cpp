/**
 🍪 the_hyp0cr1t3
 🍪 10.07.2021 17:35:05
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5, LG = 20;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, Q;
    cin >> n >> Q;
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        g[--u].pb(--v); g[v].pb(u);
    }

    vector<int> depth(n);
    array<vector<int>, LG> anc;
    for(auto& x: anc) x.assign(n, -1);

    Y([&](auto dfs, int v, int p) -> void {
        anc[0][v] = p;
        for(int k = 1; k < LG; k++)
            if(~anc[k-1][v]) anc[k][v] = anc[k-1][anc[k-1][v]];
        for(auto& x: g[v]) if(x^p) {
            depth[x] = depth[v] + 1; dfs(x, v);
        }
    })(0, -1);

    auto LCA = [&](int u, int v) {
        if(depth[u] < depth[v]) swap(u, v);
        for(int z = 0; z < LG; z++)
            if(depth[u]-depth[v] >> z & 1) u = anc[z][u];
        if(u == v) return u;
        for(int z = LG-1; ~z; z--)
            if(anc[z][u] ^ anc[z][v])
                u = anc[z][u], v = anc[z][v];
        return anc[0][u];
    };

    auto dist = [&](int u, int v) {
        return depth[u] + depth[v] - 2 * depth[LCA(u, v)];
    };

    while(Q--) {
        int u, v; cin >> u >> v;
        cout << (dist(--u, --v) & 1? "Road" : "Town") << '\n';
    }
} // ~W