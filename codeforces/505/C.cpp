/**
 🍪 the_hyp0cr1t3
 🍪 29.09.2020 16:16:42
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 30001;
int gems[N];
array<unordered_map<int, int>, N> dp;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, d, ans = 0;
    cin >> n >> d;
    for(i = 0; i < n; i++) {
        int x; cin >> x;
        gems[x]++;
    }

    for(dp[i = d][d]; i < N; i++) {
        for(auto& [len, val]: dp[i]) {
            val += gems[i];
            if(len > 1 and i+len-1 < N) chmax(dp[i+len-1][len-1], val);
            if(i+len < N) chmax(dp[i+len][len], val);
            if(i+len+1 < N) chmax(dp[i+len+1][len+1], val);
            chmax(ans, val);
        }
    } cout << ans << '\n';
}