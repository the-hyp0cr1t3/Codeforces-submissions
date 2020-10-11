/**
 🍪 the_hyp0cr1t3
 🍪 11.10.2020 14:38:37
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
    int i, j, k, n;
    cin >> n;
    for(i = 0; i*7 <= n; i++) {
        for(j = 0; j*5 + i*7 <= n; j++) {
            if((n - i*7 - j*5) % 3 == 0)
                return cout << (n - i*7 - j*5)/3 << ' ' << j << ' ' << i << '\n', 0;
        }
    } cout << -1 << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}       