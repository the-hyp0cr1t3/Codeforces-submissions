/**
 🍪 the_hyp0cr1t3
 🍪 21.10.2020 01:09:02
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

struct edge_t {
    int u, v, w;
    edge_t() = default;
    edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w < other.w; }
};

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> g(n);
    vector<edge_t> edges; edges.reserve(m);
    for(i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.pb(--u, --v, w);
        g[u].pb(i); g[v].pb(i);
    }

    vector<int64_t> cands(m);

    auto dijkstra = [&](int a, int b) {
        vector<int> vis(n);
        vector<int64_t> d(n, DESPACITO);
        priority_queue<pair<int64_t, int>> pq;
        d[a] = 0;
        for(int j = 0; j < n; j++)
            pq.emplace(-d[j], j);
        while(!pq.empty()) {
            auto [curd, v] = pq.top(); pq.pop();
            if(vis[v]++) continue;
            curd = -curd;
            for(auto j: g[v]) {
                int to = edges[j].u ^ edges[j].v ^ v;
                int w = edges[j].w;
                if(chmin(d[to], curd + w))
                    pq.emplace(-d[to], to);
            }
        }

        int64_t best = d[b];
        vector<int64_t> d2(n, DESPACITO);
        d2[b] = 0;
        vis.assign(n, 0);
        for(int j = 0; j < n; j++)
            pq.emplace(-d2[j], j);
        while(!pq.empty()) {
            auto [curd, v] = pq.top(); pq.pop();
            if(vis[v]++) continue;
            curd = -curd;
            for(auto j: g[v]) {
                int to = edges[j].u ^ edges[j].v ^ v;
                int w = edges[j].w;
                if(chmin(d2[to], curd + w))
                    pq.emplace(-d2[to], to);
            }
        }

        for(int j = 0; j < m; j++) {
            int u = edges[j].u, v = edges[j].v;
            cands[j] += min({best, d[u] + d2[v], d[v] + d2[u]});
        }
    };
    
    for(i = 0; i < k; i++) {
        int a, b; cin >> a >> b;
        dijkstra(--a, --b);
    } cout << *min_element(all(cands));
}