/**
 🍪 the_hyp0cr1t3
 🍪 13.10.2020 01:52:24
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
int a[N];
int64_t pref[N], maxdelta[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, ans = 0; int64_t d, tot = 0;
    cin >> n >> d;
    vector<int> stops{0};
    stops.reserve(n);
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            stops.pb(i);
        } else {
            tot += a[i];
            pref[i] = pref[i-1] + a[i];
            maxdelta[i] = max(maxdelta[i-1], pref[i]);
            if(maxdelta[i] > d or tot > d) return cout << -1, 0;
        }
    }

    int64_t lo = 0, hi = 0;
    for(i = 1; i < sz(stops); i++) {
        hi = min(hi, d - maxdelta[stops[i]-1]);
        if(lo > hi) return cout << -1, 0;
        hi += pref[stops[i]-1];
        lo += pref[stops[i]-1];
        if(hi < 0) ans++, hi = d;
        lo = max(0ll, lo);
    }
    hi = min(hi, d - maxdelta[n]);
    if(lo > hi) return cout << -1, 0;
    cout << ans << '\n';
}