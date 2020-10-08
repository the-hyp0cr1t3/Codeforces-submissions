/**
 🍪 the_hyp0cr1t3
 🍪 07.10.2020 16:32:19
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
int a[N];
int64_t dp[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; int64_t ans = 0;
    cin >> n;
    for(i = 0; i < n-1; i++)
        cin >> a[i], --a[i];
    a[i] = n;
    
    vector<array<int, 2>> seg(2*n);
    for(i = 0; i < n; i++)
        seg[i+n] = {a[i], -i};

    for(i = n-1; i; --i)
        seg[i] = max(seg[i<<1], seg[i<<1|1]);

    auto query = [&](int l, int r) {
        array<int, 2> res{-1, -1};
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) chmax(res, seg[l++]);
            if(r&1) chmax(res, seg[--r]);
        } return res;
    };

    for(i = n-2; ~i; --i) {
        auto q = query(i+1, a[i]+1);
        q[1] = -q[1];
        dp[i] = dp[q[1]] + n-1-i - (a[i]-q[1]);
        ans += dp[i];
    } cout << ans << '\n';
}