#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define min(a,b) (a<b?a:b)

int32_t main() {
    IOS;
    int i, n;
    ll x, y;
    cin >> n >> x >> y;
    vector<ll> dp(2*n+2);
    for(i = 0; i <= 2*n; i++) 
        dp[i] = x*i;
    for(i = 1; i <= n; i++) {
        dp[2*i] = min(dp[2*i], y + dp[i]);
        dp[2*i+1] = min(dp[2*i+1], x + y + dp[i]);
        dp[2*i-1] = min(dp[2*i-1], x + y + dp[i]);
    }
    cout << dp[n];
    return 0;
}