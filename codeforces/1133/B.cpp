#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 100 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, l, r, n, d, k, ans = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++) 
        cin >> d, a[d%k]++;
    for(l = 1, r = k-1; l < r; l++, r--)
        ans += 2*min(a[l], a[r]);
    if (l == r) ans += a[l]/2*2;
    ans += a[0]/2*2;
    cout << ans;
    return 0;
}