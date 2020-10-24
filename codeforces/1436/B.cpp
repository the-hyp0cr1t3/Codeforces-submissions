/**
 🍪 the_hyp0cr1t3
 🍪 24.10.2020 19:40:57
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
    int i, n, j;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n));
    for(i = 0; i < n; i++) {
        ans[i][i] = 1;
        if(i-1 >= 0) ans[i][i-1] = 1;
        if(i+1 < n) ans[i][i+1] = 1;
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cout << ans[i][j] << " \n"[j == n-1];
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}