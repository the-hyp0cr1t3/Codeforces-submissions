/**
 🍪 the_hyp0cr1t3
 🍪 09.11.2020 18:17:08
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
const int N = 16;
const int M = 1e4 + 5;
int a[N][M], diff[N][N], last[N][N], dp[1<<N][N][N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cin >> a[i][j];

    for(i = 0; i < n; i++) {
        dp[1<<i][i][i] = INF;
        for(j = 0; j < n; j++)
            diff[i][j] = last[i][j] = INF;
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 0; k < m; k++)
                chmin(diff[i][j], abs(a[i][k] - a[j][k]));

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            for(k = 1; k < m; k++)
                chmin(last[j][i], abs(a[i][k] - a[j][k-1]));

    // dp[mask][fst][cur]
    for(int msk = 1; msk < 1<<n; msk++) {
        int pcnt = __builtin_popcount(msk);
        for(i = 0; i < n; i++) {
            if(!(msk>>i&1)) continue;
            for(j = 0; j < n; j++) {
                if(!(msk>>j&1) or pcnt > 1 and i == j) continue;
                for(k = 0; k < n; k++) {
                    if(msk>>k&1) continue;
                    chmax(dp[msk|1<<k][i][k], min(dp[msk][i][j], diff[j][k]));
                }
            }
        }
    }

    int ans = 0;
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            chmax(ans, min(dp[(1<<n)-1][i][j], last[j][i]));
    cout << ans << '\n';

} // ~W