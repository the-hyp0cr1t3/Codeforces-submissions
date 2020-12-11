/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2020 20:11:56
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, j, n, m; int64_t ans = 0;
    cin >> n >> m;
    vector<string> a(n);
    for(auto& x: a) cin >> x;
    a.pb(string(m, '.'));

    vector<vector<int>> dp(n+1, vector<int>(m, 0));
    for(i = n-1; ~i; i--) {
        for(j = 0; j < m; j++) {
            if(a[i][j] != '*') continue;
            dp[i][j] = 1;
            if(j and j < m-1) {
                dp[i][j] = min({dp[i+1][j-1], dp[i+1][j], dp[i+1][j+1]}) + 1;
            } ans += dp[i][j];
        }
    } cout << ans << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W         