#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
#define MOD 1000000007  //1e9 + 7
const int N = 1e5 + 5;
int dp[N][2];
int32_t main() {
    IOS;
    int i, Q, k;
    cin >> Q >> k;
    dp[0][1] = 0;
    dp[0][0] = dp[1][0] = 1;
    for(i = 2; i < k; i++)
        dp[i][0] = 1, dp[i][1] = 0;
    for(i = k; i < N; i++) {
        dp[i][0] = ((1ll*dp[i-1][0] + dp[i-1][1])%MOD);
        dp[i][1] = dp[i-k][0] + dp[i-k][1];
    }
    for(i = 1; i < N; i++) {
        dp[i][0] = ((dp[i-1][0] + dp[i][0])%MOD);
        dp[i][1] = ((dp[i-1][1] + dp[i][1])%MOD);
    }
    while (Q--) {
        int l, r;
        cin >> l >> r;
        int ans = dp[r][0] - dp[l-1][0];
        if (ans<0) ans += MOD;
        ans %= MOD;
        ans = ans - dp[l-1][1] + dp[r][1];
        if (ans<0) ans += MOD;
        ans %= MOD;
        cout << ans << endl;
    }
    return 0;
}