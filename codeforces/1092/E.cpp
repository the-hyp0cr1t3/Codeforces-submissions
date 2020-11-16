/**
 🍪 the_hyp0cr1t3
 🍪 16.11.2020 13:11:03
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--, v--;
        g[u].pb(v); g[v].pb(u);
    }

    array<vector<int>, 2> d;
    d[0].assign(n, -1); d[1].assign(n, -1);
    vector<int> par(n, -1);

    auto bfs = [&] (int root, int o) {
        queue<int> q; q.push(root);
        d[o][root] = 0; int best = 0, f = root;
        while(!q.empty()) {
            auto cur = q.front(); q.pop();
            if(chmax(best, d[o][cur])) f = cur;
            for(auto nxt : g[cur]) {
                if(d[o][nxt] == -1) {
                    d[o][nxt] = d[o][cur] + 1;
                    q.push(nxt); par[nxt] = cur;
                }
            }
        } return f;
    };
    
    int mx = 0;
    vector<pair<int, int>> centres;
    centres.reserve(n);
    for(i = 0; i < n; i++) {
        if(~d[0][i]) continue;
        int x = bfs(bfs(i, 0), 1);
        int y = d[1][x];
        chmax(mx, y);
        while(d[1][x] > y/2) x = par[x];
        centres.pb(y - d[1][x], x);
    }

    sort(all(centres), greater{});
    vector<pair<int, int>> ans; ans.reserve(sz(centres));
    for(i = 1; i < sz(centres); i++) {
        chmax(mx, centres[0].first + 1 + centres[i].first);
        ans.pb(centres[0].second, centres[i].second);
    }
    if(sz(centres) >= 3)
        chmax(mx, centres[1].first + 2 + centres[2].first);

    cout << mx << '\n';
    for(auto [x, y]: ans) cout << x+1 << ' ' << y+1 << '\n';
} // ~W