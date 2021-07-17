/**
 🍪 the_hyp0cr1t3
 🍪 17.07.2021 17:40:40
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

const int64_t k_II = 1.5e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 1000 + 5;
int64_t a[N][N], dp[4][N][N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, k, n, m; int64_t c;
    cin >> n >> m >> c;

    for(i = 0; i <= n+1; i++) {
        for(j = 0; j <= m+1; j++) {
            for(k = 0; k < 4; k++)
                dp[k][i][j] = k_II;
            if(0 < i and i <= n and 0 < j and j <= m)
                cin >> a[i][j];
        }
    }

    for(i = 1; i <= n; i++)
        for(j = 1; j <= m; j++)
            dp[0][i][j] = min({a[i][j] - c * i - c * j, dp[0][i-1][j], dp[0][i][j-1]});

    for(i = 1; i <= n; i++)
        for(j = m; j; j--)
            dp[1][i][j] = min({a[i][j] - c * i + c * j, dp[1][i-1][j], dp[1][i][j+1]});

    for(i = n; i; i--)
        for(j = m; j; j--)
            dp[2][i][j] = min({a[i][j] + c * i + c * j, dp[2][i+1][j], dp[2][i][j+1]});

    for(i = n; i; i--)
        for(j = 1; j <= m; j++)
            dp[3][i][j] = min({a[i][j] + c * i - c * j, dp[3][i+1][j], dp[3][i][j-1]});


    int64_t ans = k_II;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            ans = min(ans, a[i][j] + min({
                dp[0][i-1][j] + c * i + c * j,
                dp[0][i][j-1] + c * i + c * j,
                dp[1][i-1][j] + c * i - c * j,
                dp[1][i][j+1] + c * i - c * j,
                dp[2][i+1][j] - c * i - c * j,
                dp[2][i][j+1] - c * i - c * j,
                dp[3][i+1][j] - c * i + c * j,
                dp[3][i][j-1] - c * i + c * j
            }));
        }
    }

    cout << ans;
} // ~W