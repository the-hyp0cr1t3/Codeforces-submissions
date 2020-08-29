/**
 🍪 the_hyp0cr1t3
 🍪 29.08.2020 11:18:21
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
// #define int long long
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 2e5+5;

int32_t main() {
    aylmao
    int i, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> dp(n, 0), indeg(n);   
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        --u; indeg[--v]++;
        g[u].pb(v);
    }
    queue<int> q;
    for(i = 0; i < n; i++) 
        if(!indeg[i]) q.push(i);

    while(!q.empty()) {
        auto v = q.front(); q.pop();
        for(auto& x: g[v]) {
            chmax(dp[x], dp[v] + 1);
            if(!--indeg[x]) q.push(x);
        }
    }
    cout << *max_element(all(dp));
    return 0;
}