/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 20:26:32
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
    int i, n, l; double ans = 0;
    cin >> n >> l;
    vector<int> a(n+2);
    for(i = 1; i <= n; i++)
        cin >> a[i];
    a.back() = l;
    vector<double> pref(n+2), suf(n+2);
    for(i = 1; i <= n+1; i++)
        pref[i] = pref[i-1] + 1.0*(a[i]-a[i-1])/i;
    for(i = n; ~i; i--)
        suf[i] = suf[i+1] + 1.0*(a[i+1]-a[i])/(n-i+1);

    // ps(pref);
    // ps(suf);

    cout << fixed << setprecision(8);
    for(i = 0; i <= n+1; i++) {
        double tl = pref[i];
        double tr = suf[i];
        if(tl == tr) return cout << tl << '\n', 0;
        if(tl > tr) {
            // tr(i);
            assert(i);
            tl = pref[i-1];
            double len = a[i] - a[i-1];
            double t2 = 1.0*(1.0*len - (tr-tl) * i) / (n+2);
            double t = tr + t2;
            return cout << t << '\n', 0;
        }
    }
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}