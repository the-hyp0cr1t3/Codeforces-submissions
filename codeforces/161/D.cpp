/**
 🍪 the_hyp0cr1t3
 🍪 13.09.2020 22:05:43
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
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
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

const int N = 50000 + 5;
const int K = 500 + 5;
int dp[N][K];

int32_t main() {
    aylmao
    int i, n, k; ll ans = 0;
    cin >> n >> k;
    vector<vector<int>> g(n);
    for(i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    Y([&](auto self, int v, int p) -> void {
        dp[v][0] = 1;
        for(auto& x: g[v]) { 
            if(x == p) continue; 
            self(x, v);
            for(i = 0; i < k; i++)
                dp[v][i+1] += dp[x][i];
        }
        for(auto& x: g[v]) {
            if(x == p) continue; 
            for(i = 0; i < k; i++) {
                ll rest = dp[v][k-i-1] - (i < k-1? dp[x][k-i-2] : 0);
                ans += rest * dp[x][i];
            } ans += dp[x][k-1];
        }
    })(0, -1);

    ans >>= 1;
    cout << ans << '\n';
}