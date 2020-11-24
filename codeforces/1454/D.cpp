/**
 🍪 the_hyp0cr1t3
 🍪 24.11.2020 21:29:15
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
    int64_t i, n, ans = 0, num;
    cin >> n; num = n;
    map<int64_t, int64_t> pf;
    for(i = 2; i*i <= n and n > 1; i++) {
        if(n % i) continue;
        int64_t cnt = 0;
        while(n % i == 0)
            cnt++, n /= i;
        pf[i] = cnt;
    }
    if(n > 1) pf[n] = 1;

    int64_t best = 0;
    for(auto [k, v]: pf)
        if(v > best) best = v, ans = k;

    cout << best << '\n';
    while(--best) cout << ans << ' ', num /= ans;
    cout << num << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W