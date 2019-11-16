#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define int long long
const int N = 2e5 + 5;
int a[N], pref[N];
int32_t main() {
    IOS;
    int i, j, n, m, ans = 0;
    cin >> n >> m;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a+1, a+n+1);
    for(i = 1; i <= m; i++) {
        pref[i] = a[i];
        for(j = i+m; j <= n; j+=m)
            pref[j] = pref[j-m] + a[j];
    }
    for(i = 1; i <= n; i++) 
        ans += pref[i], cout << ans << " ";
    return 0;
}