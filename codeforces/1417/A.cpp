/**
 🍪 the_hyp0cr1t3
 🍪 27.09.2020 20:36:39
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
    int i, n, k, ans = 0;
    cin >> n >> k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    sort(all(a));
    for(i = 1; i < n; i++) {
        ans += max(0, k - a[i]) / a[0];
    } cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}   