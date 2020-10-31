/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 00:36:33
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
const int INF = 2e9, MOD = 998244353;
const int N = 3000 + 5;
int64_t dp[N][2*N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, k;
    cin >> n >> k;
    dp[0][0] = 1;
    for(i = 1; i <= n; i++) {
        for(j = i; j; j--) {
            dp[i][j] = dp[i-1][j-1] + dp[i][2*j];
            if(dp[i][j] >= MOD) dp[i][j] -= MOD;
        }
    }
    cout << dp[n][k];
}