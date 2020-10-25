/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2020 22:38:00
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
    int i, j, n, m;
    cin >> n >> m;
    vector<vector<int>> rows(n, vector<int>(m)), cols(m, vector<int>(n)), ans(n);
    for(auto& x: rows)
        for(auto& y: x)
            cin >> y;
    for(auto& x: cols)
        for(auto& y: x)
            cin >> y;

    map<int, int> who;
    for(i = 0; i < n; i++)
        who[rows[i][0]] = i;

    for(j = 0; j < m; j++) {
        for(i = 0; i < n; i++)
            if(cols[j][i] == rows[0][0]) break;
        if(i < n) break;
    }

    for(i = 0; i < n; i++)
        ans[i] = rows[who[cols[j][i]]];

    for(i = 0; i < n; i++)
        for(j = 0; j < m; j++)
            cout << ans[i][j] << " \n"[j == m-1];
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}