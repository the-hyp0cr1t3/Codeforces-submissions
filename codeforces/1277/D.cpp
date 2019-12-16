#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define pb push_back
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i;
        int same[2] = {}, diff[2] = {};
        cin >> n;
        string t;
        map <string,int> s;
        vector<int> ans;
        for(i = 1; i <= n; i++) {
            cin >> t;
            s[t] = i;
            if (t.front() == t.back())
                same[t.front()-'0']++;
            else
                diff[t.front()-'0']++;
        }
        if (!diff[0] and !diff[1] and same[1] and same[0]) {
            cout << -1 << endl;
            continue;
        }
        for (auto [x,y]: s) {
            t = x;
            reverse(all(t));
            if (t.front() == t.back() or s.count(t))
                continue;
            if (diff[0] > diff[1] + 1 and t.back() == '0') ans.pb(y), diff[0]--, diff[1]++;
            else if (diff[1] > diff[0] + 1 and t.back() == '1') ans.pb(y), diff[1]--, diff[0]++;
        }
        cout << ans.size() << endl;
        for (auto& x: ans) 
            cout << x << " ";
        cout << endl;
    }
    return 0;
}