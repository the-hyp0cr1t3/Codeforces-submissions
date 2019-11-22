#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define min(a,b) (a<b?a:b)
const int N = 2e5 + 5;
int who[N], dp[N][4];
int32_t main() {
    IOS;
    int i, j, n, k1, k2, k3, a;
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for(i = 0; i < n; i++) 
        cin >> a, who[a] = i < k1? 1: i < k1+k2? 2 : 3;
    for(i = 0; i < 4; i++) 
        dp[0][i] = 0;
    for(i = 1; i <= n; i++) 
        dp[i][0] = INF;
    for(i = 1; i <= n; i++)
        for(j = 1; j < 4; j++) 
            dp[i][j] = min(dp[i-1][j] + (who[i]!=j), dp[i][j-1]);
    cout << dp[n][3];
    return 0;
}