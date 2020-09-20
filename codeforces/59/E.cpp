/**
 🍪 the_hyp0cr1t3
 🍪 20.09.2020 21:32:41
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 3000;
int d[N][N], path[N][N];

int32_t main() {
    aylmao
    int i, j, n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    set<tuple<int, int, int>> bads;
    for(i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        a--; b--; c--;
        bads.emplace(a, b, c);
    }
    
    for(i = 0; i < n; i++)
        for(j = 0; j <= n; j++)
            d[i][j] = INF, path[i][j] = -1;

    queue<pair<int, int>> q;
    q.push({0, n});
    d[0][n] = 0;
    while(!q.empty()) {
        auto [u, prv] = q.front(); q.pop();
        for(auto& v: g[u]) {
            if(!bads.count({prv, u, v}) and chmin(d[v][u], d[u][prv] + 1))
                path[v][u] = prv, q.push({v, u});
        }
    }

    auto mn = min_element(d[n-1], d[n-1]+n);
    if(*mn == INF) return cout << -1, 0;

    cout << *mn << '\n';
    int prv = mn - d[n-1], cur = n-1;

    vector<int> ans;
    ans.reserve(*mn);
    while(cur > 0) {
        ans.pb(cur+1);
        int tmp = prv;
        prv = path[cur][prv];
        cur = tmp;
    } ans.pb(1);
    reverse(all(ans));

    for(auto& x: ans) cout << x << ' ';
}