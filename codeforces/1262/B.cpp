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
        int n, i, q, prv = 0;
        bool flag = 0;
        cin >> n;
        vector<int> take(n), ans;
        iota(all(take), 1);
        reverse(all(take));
        for(i = 0; i < n; i++) {
            cin >> q;
            if (q > prv) {
                auto it = find(all(take), q);
                if (it != take.end())
                    ans.pb(q), take.erase(it);
                else
                    flag = 1;
            }
            else {
                if (take.back() < q)
                    ans.pb(take.back()), take.pop_back();
                else
                    flag = 1;
            }
            prv = q;
        }
        if (flag) {
            cout << -1 << endl;
            continue;
        }
        for (auto& x: ans) 
            cout << x << " ";
        cout << endl;
    }
    return 0;
}