#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
#define LOW 0
#define UP 1
const int N = 1e5 + 5;
int dp[N][2];
string s;

int32_t main() {
    IOS;
    cin >> s;
    int n = (int) s.length();
    for(int i = 1; i <= n; i++) {
        dp[i][UP] = dp[i-1][UP] + (islower(s[i-1])? 1 : 0);
        dp[i][LOW] = min(dp[i-1][UP], dp[i-1][LOW]) + (isupper(s[i-1])? 1 : 0);
    }
    cout << min(dp[n][UP], dp[n][LOW]);
    return 0;
}