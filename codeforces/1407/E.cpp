/**
 🍪 the_hyp0cr1t3
 🍪 09.09.2020 12:31:47
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
    int i, n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for(i = 0; i < m; i++) {
        int u, v, t; cin >> u >> v >> t;
        u--, v--;
        g[v].pb(u, t);
    }
    vector<int> d(n, INF), who(n, -1);
    d[n-1] = 0;

    queue<int> q;
    q.push(n-1);
    while(!q.empty()) {
        int v = q.front(); q.pop();
        for(auto [u, t]: g[v]) {
            if(who[u] == -1) who[u] = t;
            if(who[u] ^ t and d[u] > d[v] + 1)
                d[u] = d[v] + 1, q.push(u);
        }
    }
    cout << (d[0] == INF? -1 : d[0]) << '\n';
    for(i = 0; i < n; i++) cout << (~who[i]? who[i]^1 : 1);
    return 0;
}