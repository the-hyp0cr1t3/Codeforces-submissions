/**
 🍪 the_hyp0cr1t3
 🍪 28.10.2020 11:46:14
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
const int INF = 1e9, MOD = 1e9+7;
const int N = 5e5 + 5;
int a[N], b[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, k, ans = 0;
    cin >> n >> k;
    a[0] = -INF; a[n+1] = INF-1;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for(i = 1; i <= k; i++)
        cin >> b[i];
    b[++k] = n+1;

    auto add = [&](vector<int>& v, int val) {
        int lo = 0, hi = sz(v) - 1;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(v[mid] <= val) lo = mid + 1;
            else hi = mid - 1;
        } v[lo] = val;
    };
    
    for(i = 1; i <= k; i++) {
        int l = b[i-1], r = b[i];
        if(a[r] < a[l]) return cout << -1, 0;
        vector<int> cur(r-l-1, INF);
        for(j = l+1; j < r; j++)
            if(a[j] >= a[l]) add(cur, a[j]);
        while(!cur.empty() and cur.back() > a[r]) cur.pop_back();
        ans += r-l-1 - sz(cur);
    } cout << ans << '\n';
}