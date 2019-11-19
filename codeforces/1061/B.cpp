#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define min(a,b) (a<b?a:b)
const int N = 1e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, n, m, mx = INF;
    int64_t ans = 0;
    cin >> n >> m;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+n, greater<int>());
    for(i = 0; i < n; i++) {
        if (mx == 1) {
            ans += a[i]-1;
            continue;
        }
        if (a[i] >= mx) ans += a[i]-mx+1, a[i] = mx-1;
        ans += min(a[i+1], a[i]-1);
        mx = a[i];
    }
    cout << ans;
    return 0;
}