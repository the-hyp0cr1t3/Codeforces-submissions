/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2020 21:32:01
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
int a[N], dp[N][2], who[N][2];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, d;
    cin >> n >> m >> d;
    for(i = 0; i < m; i++) {
        int x; cin >> x;
        a[--x] = 1;
    }
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    memset(dp, -1, sizeof(dp));
    memset(who, -1, sizeof(who));
    Y([&](auto self, int v, int p) -> void {
        if(a[v]) dp[v][0] = 0, who[v][0] = v;
        for(auto& x: g[v]) { 
            if(x == p) continue; 
            self(x, v);
            if(who[x][0] == -1) continue;
            if(dp[x][0] + 1 >= dp[v][0]) {
                dp[v][1] = dp[v][0], who[v][1] = who[v][0];
                dp[v][0] = dp[x][0] + 1; who[v][0] = x;
            } else if(dp[x][0] + 1 > dp[v][1]) {
                dp[v][1] = dp[x][0] + 1; who[v][1] = x;
            }
        }
    })(0, -1);

    int ans = 0;
    Y([&](auto self, int v, int p) -> void {
        if(dp[v][0] <= d) ans++;
        for(auto& x: g[v]) { 
            if(x == p) continue;
            if(~who[v][0]) {
                if(who[v][0] ^ x) {
                    if(dp[v][0] + 1 >= dp[x][0]) {
                        dp[x][1] = dp[x][0]; who[x][1] = who[x][0];
                        dp[x][0] = dp[v][0] + 1; who[x][0] = 0;                      
                    } else if(dp[v][0] + 1 >= dp[x][1]) {
                        dp[x][1] = dp[v][0] + 1; who[x][1] = 0;                      
                    }
                } else if(~who[v][1]) {
                    if(dp[v][1] + 1 >= dp[x][0]) {
                        dp[x][1] = dp[x][0]; who[x][1] = who[x][0];
                        dp[x][0] = dp[v][1] + 1; who[x][0] = 0;                      
                    } else if(dp[v][1] + 1 >= dp[x][1]) {
                        dp[x][1] = dp[v][1] + 1; who[x][1] = 0;                      
                    }                    
                }
            }
            self(x, v);
        }
    })(0, -1);
    
    cout << ans << '\n';
}