/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 11:06:34
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5 + 5;
int a[N], dp[5][N];

int32_t main() {
    aylmao
    int i, j, k, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i];
    memset(dp, -1, sizeof(dp));
    for(j = 0; j < 5; j++)
        dp[j][0] = 0;
    for(i = 1; i < n; i++) {
        for(j = 0; j < 5; j++) {
            for(k = 0; k < 5; k++) {
                if(dp[k][i-1] == -1) continue;
                if(a[i] < a[i-1] and j < k) dp[j][i] = k;
                if(a[i] > a[i-1] and j > k) dp[j][i] = k;
                if(a[i] == a[i-1] and j != k) dp[j][i] = k;
            }
        }
    }
    for(k = 0; k < 5; k++)
        if(~dp[k][n-1]) break;

    if(k == 5) return cout << -1, 0;

    vector<int> ans; ans.reserve(n);

    for(i = n-1; ~i; i--) {
        ans.pb(k+1); k = dp[k][i];
    }

    reverse(all(ans));
    for(auto x: ans) cout << x << " ";
}