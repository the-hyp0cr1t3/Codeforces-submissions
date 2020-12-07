/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2020 19:36:07
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
const int INF = 1e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, k, n, m; bool bad = false;
    cin >> n >> m;
    vector<pair<int, int>> edges;
    vector<vector<int>> d(n, vector<int>(n, INF));
    for(i = 0; i < n; i++) d[i][i] = 0;
    for(i = 0; i < m; i++) {
        int u, v, b; cin >> u >> v >> b;
        edges.pb(--u, --v);
        d[u][v] = 1;
        d[v][u] = b? -1 : 1;
    }
    
    // bipartite, no negative cycles, maximize d[u][v]
    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                chmin(d[i][j], d[i][k] + d[k][j]);

    array<int, 2> best{-1};
    for(i = 0; i < n; i++) {
        if(d[i][i] < 0) bad = true;
        for(j = 0; j < n; j++) {
            if(d[i][j] + d[j][i] < 0) bad = true;
            chmax(best, array{d[i][j], i});
        }
        for(auto& [u, v]: edges)
            if((d[i][u] + d[i][v]) % 2 == 0) bad = true;
    }

    if(bad) return cout << "NO" << '\n', 0;

    cout << "YES" << '\n';
    cout << best[0] << '\n';
    for(i = 0; i < n; i++)
        cout << d[best[1]][i] << " \n"[i == n-1];
} // ~W 