#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, cnt = 0, ans = 0;
    string s;
    cin >> s;
    for(i = 0; i < (int) s.length(); i++) {
        if (s[i] >= 'a' and s[i] <= 'z') cnt++;
        else if (cnt) cnt--, ans++;
    }
    cout << ans;
    return 0;
}