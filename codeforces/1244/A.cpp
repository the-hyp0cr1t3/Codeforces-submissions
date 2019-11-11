#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int i, n, a, b, c, d, k;
        cin >> a >> b >> c >> d >> k;
        if ((a+c-1)/c + (b+d-1)/d <= k)
            cout << (a+c-1)/c << " " << (b+d-1)/d << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}
