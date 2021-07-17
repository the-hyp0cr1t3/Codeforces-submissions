/**
 🍪 the_hyp0cr1t3
 🍪 17.07.2021 18:47:20
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n, m;
    cin >> n >> m;
    map<int, int64_t> cost;
    while(m--) {
        int a, c; cin >> a >> c;
        int g = gcd(n, a);
        if(!cost.count(g)) cost[g] = c;
        else chmin(cost[g], c);
    }

    map<int, int64_t> dp;
    for(auto& [k, v]: cost)
        dp[k] = v * (n - k);

    int cur = dp.rbegin()->first;
    while(true) {
        auto dpcur = dp[cur];
        for(auto& [k, v]: cost) {
            int g = gcd(k, cur);
            auto val = dpcur + v * (cur - g);
            if(!dp.count(g)) dp[g] = val;
            else chmin(dp[g], val);
        }
        auto it = dp.find(cur);
        if(it == dp.begin()) break;
        cur = (--it)->first;
    }

    cout << (!dp.count(1)? -1 : dp[1]);
} // ~W