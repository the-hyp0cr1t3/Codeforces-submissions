#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
const int N = 1e5 + 5;
int x[N], s[N], dp[N], l[N], r[N];
vector<bool> lit;
int32_t main() {
    IOS;
    int i, j, n, m, res = INF;
    cin >> n >> m;
    lit.assign(m+2, 0);
    for(i = 1; i <= n; i++) {
        cin >> x[i] >> s[i];
        l[i] = max(x[i] - s[i], 0);
        r[i] = min(x[i] + s[i], m);
        for(j = 0; j <= 2*s[i]; j++) {
            int p = max(x[i]-s[i]+j, 0);
            p = min(p, m);
            lit[p] = 1;
        }
    }
    dp[0] = 0;
    for(i = 1; i <= m; i++) {
        if (lit[i]) {
            dp[i] = dp[i-1];
            continue;
        }
        res = INF;
        for(j = 1; j <= n; j++) 
            if (r[j] < i)
                res = min(res, i-r[j] + dp[max(l[j]-(i-r[j]) - 1, 0)]);
        if (res != INF)
            dp[i] = res;
        else
            dp[i] = i;
    }
    cout << dp[m];
    return 0;
}