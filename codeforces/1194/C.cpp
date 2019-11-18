#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define sz(x) (int)(x).size()

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, j, cnt[27] = {};
        string s, t, p, ans;
        cin >> s >> t >> p;
        if (s.length() > t.length()) {
            cout << "No" << endl;
            continue;
        }
        for(i = 0, j = 0; i < sz(t); i++) {
            if (j == sz(s)) break;
            if (t[i] == s[j])
                j++;
            else
                cnt[t[i]-'a']++;
        }
        if (j < sz(s)) {
            cout << "No" << endl;
            continue;
        }
        for(; i < sz(t); i++) 
            cnt[t[i]-'a']++;
        for(i = 0; i < sz(p); i++) 
            cnt[p[i]-'a']--;
        bool flag = 0;
        for(i = 0; i < 26; i++)
            if (cnt[i] > 0) flag = 1;
        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}