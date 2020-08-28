/**
 🍪 the_hyp0cr1t3
 🍪 28.08.2020 22:49:51
**/
#ifdef Ws
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define endl '\n'
#define pb emplace_back
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 5000 + 5;
ll dp[N];

int32_t main() {
    aylmao
    int i, j, n, ans;
    cin >> n;
    vector<pii> a(n);
    for(i = 0; i < n; i++) 
        cin >> a[i].first >> a[i].second;
    sort(all(a), [](const pii& u, const pii& v) { 
        return u.first + u.second < v.first + v.second;
    });

    memset(dp, -1, sizeof(dp));
    dp[0] = 0;

    for(i = 0; i < n; i++) {
        for(j = n-1; ~j; j--) {
            if(dp[j] == -1 or a[i].first < dp[j]) continue;
            if(~dp[j+1]) dp[j+1] = min(dp[j+1], dp[j] + a[i].second);
            else dp[j+1] = dp[j] + a[i].second;
        }
    }
    for(i = 0; i <= n; i++) 
        if(~dp[i]) ans = i;
    cout << ans;
    return 0;
}