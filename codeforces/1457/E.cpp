/**
 🍪 the_hyp0cr1t3
 🍪 29.11.2020 21:57:09
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k;
    cin >> n >> k; ++k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    sort(all(a), greater{});

    priority_queue<array<int64_t, 2>> pq;
    while(k--) pq.push({0, 0});

    for(i = 0; i < n; i++) {
        auto [nxt, sum] = pq.top(); pq.pop();
        sum += nxt; nxt += a[i];
        pq.push({nxt, sum});
    }

    int64_t ans = 0;
    while(!pq.empty())
        ans += pq.top()[1], pq.pop();

    cout << ans << '\n';
} // ~W