/**
 🍪 the_hyp0cr1t3
 🍪 12.10.2020 01:28:48
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, q = 0;
    cin >> n;
    vector<int> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i];

    vector<vector<int>> ans;
    while(!is_sorted(all(a))) {
        assert(++q <= n);
        int p = -1, q = -1;
        for(i = 0; i < n and p == -1; i++)
            for(j = i+1; j < n; j++)
                if(a[j] + 1 == a[i]) p = i, q = j;
        assert(~p and ~q);
        int mid = p+1;
        while(a[mid] == a[mid-1] + 1) mid++;
        vector<int> res;
        if(p) res.pb(p), reverse(a.begin(), a.begin()+p);
        res.pb(mid-p); reverse(a.begin()+p, a.begin()+mid);
        res.pb(q-mid+1); reverse(a.begin()+mid, a.begin()+q+1);
        if(n-1-q) res.pb(n-1-q), reverse(a.begin()+q+1, a.end());
        ans.pb(res); reverse(all(a));
    }

    cout << sz(ans) << '\n';
    for(auto& v: ans) {
        cout << sz(v) << ' ';
        for(auto& x: v) 
            cout << x << ' ';
        cout << '\n';
    }
}