/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2020 00:54:23
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
#define sqr(x) 1ll * (x) * (x)

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int a[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k; int64_t ans = 0;
    cin >> n >> k;
    k -= n;

    auto sum = [&](int x, int m) {
        m = min(m, x);
        return sqr(x/m) * (m - x % m)  + sqr(x/m + 1) * (x % m);
    };

    priority_queue<tuple<int64_t, int, int>> pq;
    for(i = 0; i < n; i++) {
        cin >> a[i]; ans += sum(a[i], 1);
        pq.emplace(sum(a[i], 1) - sum(a[i], 2), 1, i);
    }

    while(k--) {
        auto [delta, cnt, idx] = pq.top(); pq.pop();
        ans -= delta; ++cnt;
        delta = sum(a[idx], cnt) - sum(a[idx], cnt+1);
        pq.emplace(delta, cnt, idx);
    } cout << ans << '\n';
}