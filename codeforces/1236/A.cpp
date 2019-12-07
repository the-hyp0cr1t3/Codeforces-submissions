#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, ans = 0, a, b, c;
        cin >> a >> b >> c;
        ans = 3 * min(b, c/2);
        b -= min(b, c/2);
        ans += 3 * min(a, b/2);
        cout << ans << endl;
    }
    return 0;
}