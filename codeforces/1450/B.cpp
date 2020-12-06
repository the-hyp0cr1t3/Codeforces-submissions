/**
 🍪 the_hyp0cr1t3
 🍪 06.12.2020 20:08:23
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
#define int int64_t

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, n, k, ans = 0;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for(i = 0; i < n; i++)
        cin >> a[i][0] >> a[i][1];

    for(i = 0; i < n; i++) {
        bool bad = 0;
        for(int j = 0; j < n; j++)
            if(abs(a[j][0]-a[i][0]) + abs(a[j][1]-a[i][1]) > k)
                bad = 1;
        if(!bad) return cout << 1 << '\n', 0;
    } cout << -1 << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 