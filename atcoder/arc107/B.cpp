/**
 🍪 the_hyp0cr1t3
 🍪 31.10.2020 21:07:05
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
    int i, n, k; int64_t ans = 0;
    cin >> n >> k;

    auto get = [&](int m) {
        return m > 2*n or m < 2? 0ll : 2ll*min(n, m-1) - m + 1;
    };

    for(i = 2; i <= 2*n; i++)
        ans += get(i) * get(i+k);
    cout << ans << '\n';
}