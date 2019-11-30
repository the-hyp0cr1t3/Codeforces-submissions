#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define DESPACITO 1000000000000000000
#define min(a,b) (a<b?a:b)
const int N = 2005;
int n, t[N], c[N], prvt[N][2];
long long dp[N][N];
int32_t main() {
    IOS;
    int i, j, mxt = 0;
    long long ans = DESPACITO;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> t[i] >> c[i];
        t[i]++;
        mxt += t[i];
    }
    mxt = min(mxt, 2001);
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= mxt; j++) {
            if (!dp[i-1][j] and t[i] + prvt[max(0, j-t[i])][0] >= j)
                dp[i][j] = c[i] + dp[i-1][max(0, j-t[i])], prvt[j][1] = prvt[max(0, j-t[i])][0] + t[i];
            
            else if (t[i] + prvt[max(0, j-t[i])][0] >= j) {
                if (c[i] + dp[i-1][max(0, j-t[i])] < dp[i-1][j])
                    dp[i][j] = c[i] + dp[i-1][max(0, j-t[i])], prvt[j][1] = prvt[max(0, j-t[i])][0] + t[i];
                else
                    dp[i][j] = dp[i-1][j];
            }
            
            else
                dp[i][j] = dp[i-1][j];
        }
        for(j = 1; j <= mxt; j++) 
            prvt[j][0] = prvt[j][1];
    }
    
    for(i = n; i <= mxt; i++) 
        ans = min(ans, dp[n][i]);
    cout << ans;
    return 0;
}