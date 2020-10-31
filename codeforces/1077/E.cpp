/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 01:19:12
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
#include <ext/pb_ds/assoc_container.hpp>

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, ans = 0;
    cin >> n;
    __gnu_pbds::gp_hash_table<int, int> f;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        f[x]++;
    }
    vector<int> a; a.reserve(sz(f));
    for(auto [k, v]: f) a.pb(v);
    sort(all(a));

    for(i = 1; i <= n; i++) {
        int cur = i, res = 0;
        for(auto j = a.begin(); j != a.end(); j++) {
            auto it = lower_bound(j, a.end(), cur);
            if(it == a.end()) break;
            res += cur; cur <<= 1; j = it;
        } ans = max(ans, res);
    } cout << ans << '\n';
}