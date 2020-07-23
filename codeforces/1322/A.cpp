#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, n, active = 0, prv, bal = 0, ans = 0; string s;
    cin >> n >> s;
    for(auto& x: s) 
        bal += x == '('? 1 : -1;
    if(bal) return cout << -1, 0;

    for(i = 0; i < n; i++) {
        bal += s[i] == '('? 1 : -1;
        if(bal == -1 and s[i] == ')')
            active = 1, prv = i;
        if(bal == 0 and active)
            active = 0, ans += i-prv+1;
    }
    
    cout << ans;
    return 0;
}