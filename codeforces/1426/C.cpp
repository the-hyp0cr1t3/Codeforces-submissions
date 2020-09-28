/**
 🍪 the_hyp0cr1t3
 🍪 28.09.2020 13:42:21
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int the_real_main() {
    int i, j; int64_t n, ans = DESPACITO;
    cin >> n;
    
    for(i = 1; i*i <= n; i++) {
        int64_t x = i; int cnt = i-1;
        cnt += (n+x-1)/x - 1;
        chmin(ans, cnt);
    } cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}