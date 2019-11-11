#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 2e5 + 5;

int32_t main() {
    IOS;
    int i, n, a[N], p, ans = 0;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a+1, a+n+1);
    for(i = 1, p = 1; i <= n; i++)
            if (a[i] >= p) p++, ans++;
    cout << ans;
    return 0;
}
