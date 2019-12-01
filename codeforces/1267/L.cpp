#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()

int32_t main() {
    IOS;
    int i, j, n, len, k;
    string s, t;
    cin >> n >> len >> k >> s;
    for(i = 0; i < len; i++) 
        t += '*';
    vector<string> words(n, t);
    sort(all(s));
    int c = 0, passed = 0, prv = 0;
    for(i = 0; i < len; i++) {
        for(j = c; j < k; j++) 
            words[j][i] = s[passed++];
        t = s.substr(prv, passed-prv);
        c += (int)t.find(s[passed-1]);
        prv = passed;
    }
    for (auto& x: words) {
        for (auto& y: x) 
            if (y == '*') y = s[passed++];
        cout << x << endl;
    }
    return 0;
}