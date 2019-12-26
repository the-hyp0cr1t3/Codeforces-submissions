#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, n, l = 0, r = 0, ans = 0;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+n);
    while(r < n) {
        while (r < n and a[r]-a[l] <= 5) r++;
        ans = max(ans, r-l);
        l++; r++;
    }
    cout << ans;
    return 0;
}