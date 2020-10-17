/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 14:00:20
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
    int i, n, ans = 0;
    cin >> n;
    vector<pair<int, int>> a;
    a.reserve(n);
    for(i = 1; i <= n; i++) {
        int x; cin >> x;
        a.pb(x, i);
    } sort(all(a), greater{});

    for(i = 0; i < n; i++)
        ans += a[i].first * i + 1;

    cout << ans << '\n';
    for(auto [x, j]: a)
        cout << j << ' ';
}