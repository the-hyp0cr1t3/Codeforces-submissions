/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2020 22:31:12
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

int the_real_main() {
    int i, n;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        if(i&1)
            cout << -a[i] << ' ' << a[i-1] << " \n"[i == n-1];
    }
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}