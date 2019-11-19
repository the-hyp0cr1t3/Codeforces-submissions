#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)

int32_t main() {
    IOS;
    int i, n, a, mx = -1, last = -1;
    map <int,int> dp;
    stack<int> s, ans;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        s.push(a);
        dp[a] = max(dp[a], dp[a-1]+1);
        if (dp[a] > mx)
            mx = dp[a], last = a;
    }
    for(i = n; sz(s); i--) {
        if (s.top() == last)
            ans.push(i), last--;
        s.pop();
    }
    cout << sz(ans) << endl;
    while(sz(ans))
        cout << ans.top() << " ", ans.pop();
    return 0;
}