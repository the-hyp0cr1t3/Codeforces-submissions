/**
 🍪 the_hyp0cr1t3
 🍪 16.10.2020 18:21:21
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
const int M = 20;
int dp[1<<M];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, ans = 0; string s;
    cin >> s; n = sz(s);

    for(i = 0; i < n; i++) {
        array<int, M> vis{}; int msk = 0;
        for(int len = 0; i + len < n and len < M; len++) {
            if(vis[s[i+len]-'a']) break;
            vis[s[i+len]-'a']++;
            dp[msk |= 1 << s[i+len]-'a'] = len + 1;
        }
    }

    for(int msk = 0; msk < 1<<M; msk++)
        for(i = 0; i < M; i++)
            if(!(msk>>i&1))
                chmax(dp[msk|1<<i], dp[msk]);

    for(int msk = 0; msk < 1<<M; msk++)
        chmax(ans, dp[msk] + dp[(1<<M)-1 ^ msk]);

    cout << ans << '\n';
}