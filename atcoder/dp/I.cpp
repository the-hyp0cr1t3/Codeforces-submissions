//https://atcoder.jp/contests/dp/tasks/dp_i
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3e3 + 5;
double dp[N];
int32_t main() {
    IOS;
    int i, j, n;
    double p, ans = 0;
    cin >> n;
    cout << fixed << setprecision(11);
    dp[0] = 1;
    for(i = 1; i <= n; i++) {
        cin >> p;
        for(j = i; j >= 0; j--) 
            dp[j] = (!j? 0.0 : dp[j-1]) * p + dp[j] * (1.0 - p);
    }
    for(i = (n+1)/2; i <= n; i++) 
        ans += dp[i];
    cout << ans;
    return 0;
}