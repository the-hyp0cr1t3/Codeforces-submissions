/**
 🍪 the_hyp0cr1t3
 🍪 02.02.2021 10:52:34
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v, i); g[v].pb(u, i);
    }
    
    int64_t msk = (1LL<<n-1)-1;
    auto dfs = Y([&](auto dfs, int v, int p, int u) -> bool {
        if(v == u) return true;
        bool ret = false;
        for(auto& [x, j]: g[v]) if(x^p) {
            if(dfs(x, v, u))
                msk ^= 1LL<<j, ret = true;
        } return ret;
    });
    
    cin >> m;
    vector<int64_t> mask(m, (1LL<<n-1)-1);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        dfs(u, -1, v); swap(mask[i], msk);
    }
    
    int64_t ans = 0;
    for(msk = 1; msk < 1<<m; msk++) {
        int64_t edges = -1;
        for(i = 0; i < m; i++)
            if(msk>>i&1) edges &= mask[i];
        int mpopcnt = __builtin_popcount(msk);
        int epopcnt = __builtin_popcountll(edges);
        ans += (mpopcnt & 1? 1LL : -1LL) * (1LL << epopcnt);
    }
    ans = (1LL << n-1) - ans;
    cout << ans;
} // ~W 