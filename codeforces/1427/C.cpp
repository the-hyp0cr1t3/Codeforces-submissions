/**
 🍪 the_hyp0cr1t3
 🍪 11.10.2020 13:02:38
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
const int INF = 1e5, MOD = 1e9+7;
const int N = 2e5 + 5;
int t[N], x[N], y[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, r, n;
    cin >> r >> n;
    vector<int> dp(n+1), pref(n+1);
    for(i = 1; i <= n; i++) {
        cin >> t[i] >> x[i] >> y[i]; --x[i]; --y[i];
        dp[i] = -INF;
        for(j = i-1; i-j <= 2*r and ~j; j--)
            if(t[i] - t[j] >= abs(x[i]-x[j]) + abs(y[i]-y[j]))
                chmax(dp[i], dp[j] + 1);
        if(~j) chmax(dp[i], pref[j] + 1);
        pref[i] = max(pref[i-1], dp[i]);
    } cout << pref[n] << '\n';
}