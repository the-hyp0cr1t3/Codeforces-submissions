/**
 🍪 the_hyp0cr1t3
 🍪 18.11.2020 13:56:05
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

int simPforPolyphia() {
    int i, n, c[2], h, ans = 0; string s;
    cin >> n >> c[0] >> c[1] >> h >> s;
    for(auto& x: s)
        ans += min(c[x-'0'], c[x-'0'^1] + h);
    cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) simPforPolyphia();
} // ~W