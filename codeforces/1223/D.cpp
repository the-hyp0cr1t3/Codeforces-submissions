#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define r second
#define l first
#define pb push_back
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)
typedef pair<int, int> pii;
vector<pii> occ;
vector<int> a;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i;
        cin >> n;
        vector<int> s;
        occ.clear(), a.clear();
        occ.resize(n+1), a.resize(n+1);
        for(i = 1; i <= n; i++) 
            cin >> a[i];
        for(i = 1; i <= n; i++) {
            if (!occ[a[i]].l)
                occ[a[i]].l = i, s.pb(a[i]);
            occ[a[i]].r = i;
        }
        sort(all(s));
        int ans = 1, cur = 1;
        for (i = 0; i < sz(s) - 1; i++) {
            if (occ[s[i]].r < occ[s[i+1]].l)
                cur++, ans = max(ans, cur);
            else
                cur = 1;
        }
        cout << sz(s) - ans << endl;
    }
    return 0;
}