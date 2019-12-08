#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define all(a) a.begin(),a.end()
#define ins insert

int32_t main() {
    IOS;
    int i, n, k;
    string s, ans;
    set <char, greater<char>> ch;
    cin >> n >> k >> s;
    for (auto& x: s) 
        ch.ins(x);    
    if (k > n) {
        cout << s;
        for(i = n; i < k; i++) 
            cout << *ch.rbegin();
        return 0;
    }
    ans = s.substr(0, k);
    reverse(all(ans));
    for (i = 0; i < k; i++) {
        char prv = '*';
        for (auto& c: ch) {
            if (c == ans[i]) break; 
            prv = c;
        }
        if (prv != '*')
            {ans[i] = prv; break;}
        else
            ans[i] = *ch.rbegin();
    }
    reverse(all(ans));
    cout << ans;
    return 0;
}