/**
 🍪 the_hyp0cr1t3
 🍪 31.08.2020 15:26:24
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int int64_t
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, n; ll p, l, AWP, d;
    cin >> n >> p >> l >> AWP >> d;
    vector<ll> cost1(n), cost2(n), dp(n+1, DESPACITO);
    for(i = 0; i < n; i++) {
        int a; cin >> a;
        cost1[i] = p * a + AWP;
        cost2[i] = min(p * a + p, l) + p;
        chmin(cost2[i], cost1[i]);
        chmin(cost1[i], cost2[i] + 2*d);
    }
    for(dp[i = 0] = 0; i < n; i++) {
        chmin(dp[i+1], dp[i] + cost1[i] + d);
        chmin(dp[i+1], dp[i] + cost2[i] + 3*d);
    	if(i+1 < n) chmin(dp[i+2], dp[i] + cost2[i] + cost2[i+1] + 4*d);
        if(i+2 == n) chmin(dp[i+2], dp[i] + cost2[i] + cost1[i+1] + 3*d);
    }
    dp[n] -= d;
    cout << dp[n];
    return 0;
}