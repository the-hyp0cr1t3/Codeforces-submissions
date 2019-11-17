#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
#define INF 2000000000
#define l first
#define r second
typedef pair<int, int> pii;
const int N = 1e5 + 5;
pii dp[N];
string s;

int32_t main() {
    IOS;
    cin >> s;
    int i, cnt = 0, ans = INF, n = (int) s.length();
    for(i = 1; i <= n; i++) 
        cnt += (isupper(s[i-1])? 1 : 0);
    dp[1] = {0, cnt};
    for(i = 2; i <= n; i++) {
        dp[i].l = dp[i-1].l + (islower(s[i-2])? 1 : 0);
        dp[i].r = dp[i-1].r - (isupper(s[i-2])? 1 : 0) ;
    }
    dp[n+1].l = dp[n].l + (islower(s[n-1])? 1 : 0);
    dp[n+1].r = 0;
    for(i = 1; i <= n+1; i++)
        ans = min(ans, dp[i].l + dp[i].r);
    cout << ans;
    return 0;
}