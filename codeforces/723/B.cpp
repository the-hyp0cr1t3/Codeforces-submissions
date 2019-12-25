#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, n;
    string s;
    cin >> n;
    cin >> s;
    int p = 0, ans = 0, cnt = 0;
    int prv_ = -1;
    for(i = 0; i < (int)s.length(); i++) {
        if (s[i] == '(') p++, ans = max(ans, i-prv_-1), prv_ = i;
        if (s[i] == ')') p--, cnt += bool(i-prv_-1), prv_ = i;
        if (s[i] == '_') {
            if (!p) ans = max(ans, i-prv_-1);
            else cnt += bool(i-prv_-1);
            prv_ = i;
        }
    }
    if (!p) ans = max(ans, i-prv_-1);
    cout << ans << " " << cnt;
    return 0;
}