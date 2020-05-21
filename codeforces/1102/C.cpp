#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, n, x, y, a, cnt = 0;
    cin >> n >> x >> y;
    for(i = 0; i < n; i++) {
        cin >> a;
        if (a <= x) cnt++;
    }
    if (x>y)
        cout << n;
    else
        cout << (cnt+1)/2;
    return 0;
}