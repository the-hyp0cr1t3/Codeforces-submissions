#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define ff first
#define ss second
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<ll, int> pli;
const int N = 1e5 + 5;
ll a[N];
int32_t main() {
    IOS;
    int i, n, m, u, v;
    ll d;
    cin >> n >> m;
    for(i = 0; i < m; i++) {
        cin >> u >> v >> d;
        a[--u] -= d;
        a[--v] += d;
    }
    set <pli> s;
    vector<vector<ll>> ans; 
    for(i = 0; i < n; i++)
        if (a[i]) s.ins({a[i], i});
    while(sz(s)) {
        assert(sz(s)!=1);
        pli x = *s.begin();
        pli y = *s.rbegin();
        auto it = s.end(); --it;
        s.erase(s.begin());
        s.erase(it);
        ll z = min(-x.ff, y.ff);
        y.ff -= z;
        x.ff += z;
        vector<ll> res = {x.ss+1, y.ss+1, z};
        ans.pb(res);
        if (x.ff) s.ins({x.ff, x.ss}); 
        if (y.ff) s.ins({y.ff, y.ss}); 
    } 
    cout << ans.size() << endl;
    for (auto& x: ans)
        for (i = 0; i < 3; i++) 
            cout << x[i] << " \n"[i==2];
    return 0;
}