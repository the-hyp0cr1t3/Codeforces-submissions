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
using pii = tuple<int64_t, int64_t, int64_t>;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, k; int64_t ans = 0, cursum = 0;
    cin >> n >> k; ++k;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    sort(all(a), greater{});

    // for(i = 0; i < n and cursum >= 0; i++) {
        // if()
        // ans += cursum;
        // cursum += a[i];
    // }

    // priority_queue<pii, vector<pii>, greater<pii>> pq;
    priority_queue<pii> pq;
    while(k--) pq.emplace(0, 0, 0);

    for(i = 0; i < n; i++) {
        auto [nxt, sum, cur] = pq.top(); pq.pop();
        cur = nxt; sum += nxt; nxt += a[i];
        pq.emplace(nxt, sum, cur);
    }

    while(!pq.empty()) {
        ans += get<1>(pq.top());
        pq.pop();
    }

    cout << ans << '\n';
} // ~W