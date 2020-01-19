#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int dp[10][10][10];
int32_t main() {
    IOS;
    int i, j; string s; cin >> s;
    for (int k = 0; k < (int)s.size(); k++) {
        int d = s[k]-'0';
        for(i = 1; i < 10; i++)
            for(j = 1; j < 10; j++)
                if (dp[0][i][j]) dp[i][j][d] = 1;
        for(i = 1; i < 10; i++)
            if (dp[0][0][i]) dp[0][i][d] = 1;
        dp[0][0][d] = 1; 
    }
    for(i = 0; i <= 999; i+=8)
        if (dp[i/100][(i%100)/10][i%10]) return cout << "YES" << endl << i, 0;
    cout << "NO";
    return 0;
}