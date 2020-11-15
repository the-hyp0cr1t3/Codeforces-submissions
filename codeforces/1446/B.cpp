/**
 🍪 the_hyp0cr1t3
 🍪 15.11.2020 20:59:04
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 5000 + 5;
int dp[N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, ans = 0; string s, t;
    cin >> n >> m >> s >> t;
    s = '#' + s; t = '#' + t;

    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if(s[i] == t[j])
                chmax(dp[i][j], dp[i-1][j-1] + 4 - 2);
            chmax(dp[i][j], dp[i-1][j] - 1);
            chmax(dp[i][j], dp[i][j-1] - 1);
            chmax(ans, dp[i][j]);
        }
    } cout << ans << '\n';
} // ~W