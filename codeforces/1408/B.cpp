/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 21:13:13
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
    int i, n, k;
    cin >> n >> k; --k;
    vector<int> v(n);
    for(auto& x: v) cin >> x;
    sort(all(v)); v.erase(unique(all(v)), v.end());
    
    if(k == 0) cout << (sz(v) == 1? 1 : -1) << '\n', 0;
    else cout << max((sz(v)+k-2)/k, 1) << '\n';

    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}   