//https://atcoder.jp/contests/dp/tasks/dp_e
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define DESPACITO 1000000000000000000
#define ll long long
using namespace std;
#define max(a,b) (a>b?a:b)
typedef pair<int, int> pii;
const int N = 100 + 5;
const int M = 1e5 + 5;
int val[N], wt[N];
ll dp[N][M];
int32_t main() {
    IOS;
    int i, j, n, W, ans = 0;
    cin >> n >> W;
    for(i = 1; i <= n; i++) 
        cin >> wt[i] >> val[i];
    for(i = 0; i <= n; i++)
        for(j = 0; j <= M; j++)
            dp[i][j] = DESPACITO;
    dp[0][0] = 0;
    for(i = 1; i <= n; i++) 
        for(j = 0; j < M; j++) 
            dp[i][j] = min(dp[i-1][j], wt[i] + dp[i-1][max(0, j-val[i])]);
    for(i = 1; i <= M; i++) 
        if (dp[n][i] <= W) ans = i;
    cout << ans;
    return 0;
}