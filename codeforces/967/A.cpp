#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, n, s, h, m, prv, t;
    cin >> n >> s;
    cin >> h >> m;
    prv = h*60 + m;
    if (prv > s)
        return cout << "0 0", 0;
    for(i = 1; i < n; i++) {
        cin >> h >> m, t = h*60 + m;
        if (t - prv > 2*s + 1) return cout << (prv + s + 1)/60 << " " << (prv + s + 1)%60, 0;
        prv = t;
    }
    return cout << (prv + s + 1)/60 << " " << (prv + s + 1)%60, 0;
}