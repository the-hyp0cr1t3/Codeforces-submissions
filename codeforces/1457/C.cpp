/**
 🍪 the_hyp0cr1t3
 🍪 29.11.2020 20:29:47
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
#define int int64_t

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t ocoiek() {
    int i, n, p, k, x, y, ans = DESPACITO; string s;
    cin >> n >> p >> k >> s >> x >> y;
    
    s = '#' + s.substr(p-1);
    n = sz(s) - 1;
    vector<int> pref(n+2*k);
    for(i = n; i; i--)
        pref[i] = pref[i+k] + x * (s[i] == '0');

    for(i = 1; i <= n; i++)
        ans = min(ans, y*(i-1) + pref[i]);

    cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W