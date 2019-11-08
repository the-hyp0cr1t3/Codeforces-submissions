#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define DESPACITO 1000000000000000000

using namespace std;
const int N = 1e3 + 5;

int32_t main() {
    IOS;
    int i, n, s, a[N], ans = DESPACITO, sum = 0;
    cin >> n >> s;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]<ans) ans = a[i];
    }
    for(i = 0; i < n; i++) 
        sum += (a[i] - ans);
    if (s > sum + n*ans)
        return cout << -1, 0;
    s-=sum;
    if (s<=0)
        return cout << ans, 0;
    while (s > 0)
        s -= n, ans--;
    cout << ans;
    return 0;
}