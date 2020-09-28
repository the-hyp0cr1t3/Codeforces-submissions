/**
 🍪 the_hyp0cr1t3
 🍪 28.09.2020 13:39:41
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
    int i, n, m;
    cin >> n >> m;
    bool ok = 1, present = 0;
    if(m&1) ok = 0;
    for(i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        if(b == c) present = 1;
    }
    cout << (ok and present? "YES" : "NO") << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}