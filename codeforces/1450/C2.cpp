/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2020 16:04:39
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

int ocoiek() {
    int i, j, k = 0, n;
    cin >> n;
    vector<string> a(n);
    for(auto& x: a) cin >> x;

    array<array<vector<pair<int, int>>, 2>, 3> pos;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(a[i][j] != '.') k++;
            if(a[i][j] == 'X')
                pos[(i+j)%3][0].pb(i, j);
            if(a[i][j] == 'O')
                pos[(i+j)%3][1].pb(i, j);
        }
    }

    for(int p = 0; p < 3; p++) {
        for(int q = 0; q < 3; q++) {
            if(p ^ q and sz(pos[p][0]) + sz(pos[q][1]) <= k/3) {
                for(auto [x, y]: pos[p][0]) a[x][y] = 'O';
                for(auto [x, y]: pos[q][1]) a[x][y] = 'X';
                for(auto x: a) cout << x << '\n';
                return 0;
            }
        }
    }

    assert(false);
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 