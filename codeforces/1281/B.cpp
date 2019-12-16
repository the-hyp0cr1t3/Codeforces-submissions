#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define s second
#define f first
#define sz(x) (int)(x).size()

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i;
        string s, t;
        cin >> s >> t;
        map <char,int> cnt;
        for (auto& x: s) 
            cnt[x]++;
        for (i = 0; i < sz(s); i++) {
            if (cnt.begin()->f != s[i]) {
                auto j = s.rfind(cnt.begin()->f);
                assert(j != string::npos);
                s[j] = s[i];
                s[i] = cnt.begin()->f;
                break;
            }
            else {
                cnt.begin()->s--;
                if (!cnt.begin()->s) cnt.erase(cnt.begin());
            }
        }
        if (s < t) cout << s << endl;
        else cout << "---" << endl;
    }
    return 0;
}