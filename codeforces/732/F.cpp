/**
 🍪 the_hyp0cr1t3
 🍪 21.09.2020 14:26:46
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<pair<int, int>> edges, goodedges;
    edges.reserve(m); goodedges.reserve(m);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        edges.pb(u, v);
        g[u].pb(v, i);
        g[v].pb(u, i);
    } i = 0;
    
    vector<int> vis(n), tin(n), low(n), used(m);
    Y([&](auto dfs, int v, int p) -> void {
        vis[v] = 1;
        tin[v] = low[v] = i++;
        for(auto& [x, j]: g[v]) {
            if(x == p) continue;
            if(!vis[x]) dfs(x, v);
            else chmin(low[v], tin[x]);
            chmin(low[v], low[x]);
            if(!used[j] and low[x] <= tin[v])
                goodedges.pb(v, x);
            used[j] = 1;
        }
    })(0, -1);

    vector<int> data(n+1, -1);
    
    auto par = Y([&](auto self, int pp) -> int {
        return data[pp] < 0 ? pp : data[pp] = self(data[pp]);
    }); auto SZ = [&](int x) { return -data[par(x)]; };
    
    auto merge = [&](int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        return true;
    };
    
    for(auto& [u, v]: goodedges)
        merge(u, v);

    int best = 0, root;
    for(i = 0; i < n; i++)
        if(chmax(best, SZ(i))) root = i;

    vis.assign(n, 0); used.assign(m, 0);
    Y([&](auto dfs, int v) -> void {
        vis[v] = 1;
        for(auto& [x, j]: g[v]) { 
            if(!used[j]++) edges[j] = {x, v};
            if(!vis[x]) dfs(x);
        }
    })(root);
    
    cout << best << '\n';
    for(auto& [u, v]: edges)
        cout << u+1 << ' ' << v+1 << '\n';
}