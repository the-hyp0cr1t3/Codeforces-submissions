#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, n, idx, cnt = 0;
    cin >> n;
    cin >> a[0];
    for(i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] < a[i-1])
            cnt++, idx = i;
    }
    if (a[0] < a[n-1] and n > 2)
        cnt++, idx = 0;
    if (!cnt)
        cout << 0;
    else if (cnt > 1)
        cout << -1;
    else
        cout << n - idx;
    return 0;
}