#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define DESPACITO 1000000000000000000 //1e18
#define all(a) a.begin(),a.end()
#define idx second
#define val first
#define pb push_back
#define min(a,b) (a<b?a:b)
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, path[N];
ll dp[N];
pii a[N];
vector <pii> ans;
int32_t main() {
    IOS;
    int i, j, cnt = 0;
    ll check;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i].val, a[i].idx = i;
    sort(a+1, a+n+1);
    path[0] = 0;
    path[3] = 3, path[4] = 4, path[5] = 5;
    dp[0] = dp[1] = dp[2] = DESPACITO;
    dp[3] = a[3].val-a[1].val;
    dp[4] = a[4].val-a[1].val;
    dp[5] = a[5].val-a[1].val;
    for(i = 6; i <= n; i++) {
        check = dp[i-3] + a[i].val - a[i-2].val;
        dp[i] = check, path[i] = 3;

        check = dp[i-4] + a[i].val - a[i-3].val;
        if (check <= dp[i])
            dp[i] = check, path[i] = 4;
        
        check = dp[i-5] + a[i].val - a[i-4].val;
        if (check <= dp[i])
            dp[i] = check, path[i] = 5;
    }
    i = n;
    while (path[i]) {
        for(j = 0; j < path[i]; j++) 
            ans.pb({a[i-j].idx, cnt+1});
        i -= path[i];
        cnt++;
    }
    cout << dp[n] << " " << cnt << endl;
    sort(all(ans));
    for (auto& x: ans)
        cout << x.second << " "; 
    return 0;
}