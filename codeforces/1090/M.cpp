#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
#define max(a,b) (a>b?a:b)
int32_t main() {
    IOS;
    int i, n, a, prv, ans = 1, cnt = 1, k;
    cin >> n >> k;
    cin >> prv;
    while (--n) {
        cin >> a;
        if (a == prv)
            ans = max(ans, cnt), cnt = 0;
        cnt++;
        prv = a;
    }
    ans = max(ans, cnt);
    cout << ans;
    return 0;
}