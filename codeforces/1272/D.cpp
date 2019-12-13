#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define max(a,b) (a>b?a:b)
const int N = 2e5 + 5;
int a[N], dp[N], pd[N];
int32_t main() {
    IOS;
    int i, n;
    cin >> n;
    int ans = 0;
    cin >> a[0];
    dp[0] = 1;
    for(i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] > a[i-1])
            dp[i] = dp[i-1] + 1;
        else
            dp[i] = 1;
        ans = max(ans, dp[i]);
    }
    pd[n-1] = 1;
    for(i = n-2; i >= 0; i--) {
        if (a[i] < a[i+1])
            pd[i] = pd[i+1] + 1;
        else
            pd[i] = 1;
    }
    ans = max(ans, dp[n-2]);
    ans = max(ans, pd[1]);
    for(i = 1; i < n-1; i++) 
        if (a[i+1] > a[i-1])
            ans = max(ans, dp[i-1] + pd[i+1]);
    cout << ans;
    return 0;
}