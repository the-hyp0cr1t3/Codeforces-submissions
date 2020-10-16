/**
 🍪 the_hyp0cr1t3
 🍪 16.10.2020 17:14:34
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
    int i, n; int sum = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        sum += x;
    } cout << (sum + n-1)/n << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}