/**
 🍪 the_hyp0cr1t3
 🍪 24.11.2020 21:48:40
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
    int i, n;
    cin >> n;
    vector<vector<int>> pos(n+1);
    for(i = 1; i <= n; i++) {
        int x; cin >> x;
        pos[x].pb(i);
    }

    for(i = 1; i <= n; i++) 
        if(sz(pos[i]) == 1)
            return cout << pos[i][0] << '\n', 0;

    cout << -1 << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W