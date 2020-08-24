/**
 🍪 the_hyp0cr1t3
 🍪 25.08.2020 00:48:08
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int N = 2e5+5;

int32_t main() {
    aylmao
    int i, n, ans = 0;
    cin >> n;
    vector<vector<int>> g(n), dp(n, vector<int>(3));
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    
    Y([&](auto self, int v, int p, int d) -> void {
        int best = INF;
        for(auto& x: g[v]) { 
            if(x == p) continue; 
            self(x, v, d+1);
            dp[v][0] += min({dp[x][0], dp[x][1], dp[x][2]});
            dp[v][1] += min(dp[x][0], dp[x][1]);
            chmin(best, dp[x][0] - dp[x][1]);
            dp[v][2] += dp[x][1];
        }
        if(sz(g[v]) == 1) dp[v][1] = 1;
        else dp[v][1] += max(0, best);
        dp[v][0]++;
        if(d == 2) ans += min({dp[v][0], dp[v][1], dp[v][2]});
    })(0, -1, 0);
    
    cout << ans;
    return 0;
}