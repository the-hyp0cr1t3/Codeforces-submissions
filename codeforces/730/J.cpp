/**
 🍪 the_hyp0cr1t3
 🍪 01.09.2020 17:45:19
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

int32_t main() {
    aylmao
    int i, j, k, n, sum = 0, total = 0, capacity = 0;
    cin >> n;
    vector<pii> a(n);
    for(i = 0; i < n; i++) 
        cin >> a[i].first, total += a[i].first;
    for(i = 0; i < n; i++) 
        cin >> a[i].second, capacity += a[i].second;
    
    sort(all(a), [](const auto& u, const auto& v) { 
        return u.second > v.second;
    });
    for(i = 0; i < n; i++) {
        sum += a[i].second;
        if(sum >= total) break;
    }
    int K = i+1;

    vector<vector<int>> dp(K+2, vector<int>(capacity+1, INF));
    dp[0][0] = 0;
    // dp[k][j] = min time spent to move stuff to
    // k selected bottles having total capacity j 
    // from all other ones
    for(i = 0; i < n; i++) {
        vector<vector<int>> dp2(K+2, vector<int>(capacity+1, INF));
        for(k = 0; k <= K; k++) {
            for(j = 0; j <= capacity; j++) { 
                // choose i-th bottle
                if(j+a[i].second <= capacity)
                    chmin(dp2[k+1][j+a[i].second], dp[k][j]);
                // empty i-th bottle
                chmin(dp2[k][j], dp[k][j] + a[i].first);
            }
        }
        dp = dp2;
    }

    cout << K << " " << *min_element(dp[K].begin()+total, dp[K].end());
    return 0;
}