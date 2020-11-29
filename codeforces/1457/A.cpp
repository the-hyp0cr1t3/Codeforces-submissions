/**
 🍪 the_hyp0cr1t3
 🍪 29.11.2020 20:18:49
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
    int i, n, m, r, c, ans = 0;
    cin >> n >> m >> r >> c;
    ans = max(ans, abs(1-r) + abs(1-c));
    ans = max(ans, abs(n-r) + abs(1-c));
    ans = max(ans, abs(1-r) + abs(m-c));
    ans = max(ans, abs(n-r) + abs(m-c));
    cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W