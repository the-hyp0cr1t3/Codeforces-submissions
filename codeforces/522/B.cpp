#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
int w[N], h[N];
int32_t main() {
    IOS;
    int i, n, wsum = 0, mx1 = 0, mx2 = 0;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> w[i] >> h[i];
        wsum += w[i];
        if (h[i] > mx1) {
            if (mx1 > mx2) 
                mx2 = mx1;
            mx1 = h[i];
            continue;
        }
        if (h[i] > mx2)
            mx2 = h[i];
    }
    for(i = 1; i <= n; i++) {
        int ans = wsum - w[i];
        ans *= h[i] == mx1? mx2 : mx1;
        cout << ans << " ";
    }
    return 0;
}