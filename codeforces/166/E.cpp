#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define pb push_back
const int N = 1e7 + 5;
int dp[N][2];
int32_t main() {
    IOS;
    int i, n;
    cin >> n;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(i = 1; i <= n; i++) {
        dp[i][0] = dp[i-1][1];
        dp[i][1] = (int)((3ll*dp[i-1][0]%MOD) + (2ll*dp[i-1][1]%MOD))%MOD;
    }
    cout << dp[n][0];
    return 0;
}