/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 13:00:33
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
int a[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    vector<int64_t> sub(n), dp(n);
    Y([&](auto self, int v, int p) -> void {
        sub[v] += a[v];
        for(auto& x: g[v]) {
            if(x == p) continue;
            self(x, v);
            sub[v] += sub[x];
            dp[v] += dp[x] + sub[x];
        }
    })(0, -1);
    
    Y([&](auto self, int v, int p) -> void {
        for(auto& x: g[v]) { 
            if(x == p) continue;
            dp[x] = dp[v] + sub[0] - 2ll * sub[x];
            self(x, v);
        }
    })(0, -1);
    
    cout << *max_element(all(dp)) << '\n';
} // ~W