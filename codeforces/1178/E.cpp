#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define sz(x) (int)(x).size()

int32_t main() {
    IOS;
    int n, l, r;
    string s, ans;
    cin >> s;
    n = sz(s);
    if (n < 4)
        return cout << s[0], 0;
    for(l = 0, r = n-1; l < r;) {
        if (s[l] == s[r])
            ans += s[l], l++, r--;
        else if (s[l] == s[r-1] and r-1 > l)
            ans += s[l], l++, r-=2;
        else
            l++;
    }
    cout << ans;
    if (l == r)
        cout << s[l];
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}