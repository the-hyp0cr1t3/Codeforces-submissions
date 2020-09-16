/**
 🍪 the_hyp0cr1t3
 🍪 16.09.2020 23:34:42
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
const int N = 2e5 + 5;

int32_t main() {
    aylmao
    int i, n, m , k;
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v, i);
        g[v].pb(u, i);
    }
    
    vector<int> whichedge(n, -1), d(n);
    vector<vector<int>> alternatives(m);
    vector<string> ans{string(m, '0')};
    ans.reserve(k);

    queue<int> q;
    q.push(0);
    d[0] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        for(auto [nxt, e] : g[cur]) {
            if(!d[nxt]) {
                d[nxt] = d[cur] + 1;
                whichedge[nxt] = e;
                ans[0][e] = '1';
                q.push(nxt);
            } else if(d[nxt] == d[cur] + 1)
                alternatives[whichedge[nxt]].pb(e);
        }
    }

    auto split = [&](int e, vector<int> alts) {
        if(sz(ans) == k or alts.empty()) return;
        int times = sz(alts), _sz = sz(ans);
        while(times-- and sz(ans) < k) {
            for(int j = 0; j < _sz and sz(ans) < k; j++) {
                ans.pb(ans[j]);
                ans.back()[e] = '0';
                ans.back()[alts[times]] = '1';
            }
        }
    };

    for(i = 0; i < m; i++)
        split(i, alternatives[i]);

    cout << sz(ans) << '\n';
    for(auto& x: ans) cout << x << '\n';
}