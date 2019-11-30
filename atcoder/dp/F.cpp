#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)
string s, t, res;
int n, m;
vector<vector<int>> dp;
int32_t main() {
    IOS;
    int i = 1, j = 1;
    cin >> s >> t;
    n = sz(s), m = sz(t);
    dp.resize(n+1, vector<int>(m+1));
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            if (s[i-1] == t[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    //cout << dp[n][m] << endl;
    i = n, j = m;
    while(i and j) {
        if (dp[i][j] == dp[i-1][j]) 
            i--;
        else if (dp[i][j] == dp[i][j-1]) 
            j--;
        else 
            res += s[i-1], i--, j--;
    }
    reverse(all(res));
    cout << res;
    return 0;
}