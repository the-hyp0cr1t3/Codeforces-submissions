#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define min(a,b) (a<b?a:b)
const int N = 2e5 + 5;
int who[N], pref[N], minsuf[N];
int32_t main() {
    IOS;
    int i, n, a, k1, k2, k3, ans = INF, suf, prvsuf;
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for(i = 0; i < n; i++) 
        cin >> a, who[a] = i < k1? 1 : i < k1+k2? 2 : 3;
    pref[0] = k1;
    prvsuf = minsuf[n+1] = k3;
    for(i = 1; i <= n; i++)
        pref[i] = pref[i-1] + (who[i]==2) - (who[i]==1);
    for(i = n; i >= 0; i--) 
        suf = prvsuf + (who[i]==2) - (who[i]==3), minsuf[i] = min(minsuf[i+1], suf), prvsuf = suf;
    for(i = 0; i <= n; i++)
        ans = min(ans, pref[i] + minsuf[i+1]);
    cout << ans;
    return 0;
}