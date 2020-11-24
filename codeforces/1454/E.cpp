/**
 🍪 the_hyp0cr1t3
 🍪 24.11.2020 21:07:52
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

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

int ocoiek() {
    int i, n;
    cin >> n;
    vector<vector<int>> g(n);
    for(i = 0; i < n; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }
    
    vector<int> vis(n), par(n, -1), cycle;
    cycle.reserve(n);
    Y([&](auto self, int v, int p) -> void {
        vis[v] = 1; par[v] = p;
        for(auto& x: g[v]) { 
            if(x == p) continue; 
            if(vis[x] and cycle.empty()) {
                int u = v; cycle.pb(u);
                while(u ^ x)
                    cycle.pb(u = par[u]);
            } else if (!vis[x]) {
                self(x, v);
            }
        }
    })(0, -1);
    
    auto dfs = Y([&](auto self, int v, int p) -> int {
        int cnt = 1;
        for(auto& x: g[v]) { 
            if(x == p) continue; 
            cnt += self(x, v);
        } return cnt;
    });

    int64_t ans = 1ll * n * (n-1);
    for(i = 0; i < sz(cycle); i++) {
        int64_t cnt = 1;
        for(auto& x: g[cycle[i]]) {
            if(x == cycle[(i-1+sz(cycle)) % sz(cycle)] or
                x == cycle[(i+1) % sz(cycle)]) continue;
            cnt += dfs(x, cycle[i]);
        } ans -= cnt * (cnt-1) / 2;
    }

    cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W