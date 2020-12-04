/**
 🍪 the_hyp0cr1t3
 🍪 04.12.2020 18:38:04
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
    int i, n, m, ans = 0;
    cin >> n >> m;
    set<int> have;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        have.insert(x);
    }

    for(i = 0; i < m; i++) {
        int x; cin >> x;
        if(have.count(x)) ans++;
    }

    cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 