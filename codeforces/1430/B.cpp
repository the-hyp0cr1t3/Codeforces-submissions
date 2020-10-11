/**
 🍪 the_hyp0cr1t3
 🍪 11.10.2020 14:44:08
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
    int i, n, k; int64_t ans = 0;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for(i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a), greater{});
    int64_t sum = 0;
    for(i = 0; i < k; i++)
        sum += a[i].first;

    for(i = 0; i < n; i++) {
        if(i < k)
            chmax(ans, sum + a[k].first);
        else
            chmax(ans, sum + a[i].first);
    } cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}