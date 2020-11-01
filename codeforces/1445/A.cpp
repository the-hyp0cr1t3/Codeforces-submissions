/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 22:08:55
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
int a[N], b[N];

int the_real_main() {
    int i, n, x;
    cin >> n >> x;
    for(i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for(i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b+n, greater{});
    for(i = 0; i < n; i++)
        if(a[i]+b[i] > x) return cout << "NO" << '\n', 0;
    cout << "YES" << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}