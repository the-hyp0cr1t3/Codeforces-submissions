/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2020 14:40:05
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int the_real_main() {
    int i, n;
    cin >> n;
    vector<string> a(n);
    for(auto& x: a) cin >> x;
    vector<pair<int, int>> ans;
    if(a[0][1] == a[1][0]) {
        if(a[n-1][n-2] == a[0][1]) ans.pb(n-1, n-2);
        if(a[n-2][n-1] == a[0][1]) ans.pb(n-2, n-1);
    } else if(a[n-1][n-2] == a[n-2][n-1]) {
        if(a[n-1][n-2] == a[0][1]) ans.pb(0, 1);
        if(a[n-2][n-1] == a[1][0]) ans.pb(1, 0);
    } else {
        ans.pb(1, 0);
        if(a[n-1][n-2] == a[0][1]) ans.pb(n-1, n-2);
        if(a[n-2][n-1] == a[0][1]) ans.pb(n-2, n-1);        
    }
    assert(sz(ans) <= 2);
    cout << sz(ans) << '\n';
    for(auto [u, v]: ans) cout << u+1 << ' ' << v+1 << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}