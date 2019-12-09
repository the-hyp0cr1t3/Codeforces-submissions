#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int32_t main() {
    IOS;
    int i, j;
    char n, c;
    string s, t, p;
    vector<string> ans;
    cin >> s >> t;
    if (t[0] - s[0] > 0) 
        n = 'R', i = 1;
    else
        n = 'L', i = -1;
    if (t[1] - s[1] > 0) 
        c = 'U', j = 1;
    else
        c = 'D', j = -1;
    while(t != s) {
        if (s[0] != t[0] and s[1] != t[1]) {
            s[0] = (char) (s[0]+i);
            s[1] = (char) (s[1]+j);
            p = n; p += c;
            ans.push_back(p);
        }
        else if (s[0] != t[0]) {
            s[0] = (char) (s[0]+i);
            p = n;
            ans.push_back(p);
        }
        else {
            s[1] = (char) (s[1]+j);
            p = c;
            ans.push_back(p);
        }
    }
    cout << ans.size() << endl;
    for (auto& x: ans) 
        cout << x << endl;
    return 0;
}