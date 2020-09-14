/**
 🍪 the_hyp0cr1t3
 🍪 14.09.2020 12:04:22
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

using ll = int64_t;
using pii = pair<int,int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;

const int N = 3000 + 5;
int d[N][N], to[N][N], from[N][N];

int32_t main() {
    aylmao
    int i, j, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        u--, v--;
        g[u].pb(v);
    }
    
    for(i = 0; i <= n; i++) {
        for(j = 0; j <= n; j++) {
            to[i][j] = from[i][j] = j;
            d[i][j] = INF;
        }
    }

    auto bfs = [&] (int root) {
        queue<int> q;
        q.push(root);
        d[root][root] = 0;
        while(!q.empty()) {
            auto cur = q.front();
            q.pop();
            for(auto nxt : g[cur]) {
                if(d[root][nxt] > d[root][cur] + 1) {
                    d[root][nxt] = d[root][cur] + 1;
                    q.push(nxt);
                }
            }
        }
    };
    
    for(i = 0; i < n; i++) bfs(i);

    auto cmpto = [&](const auto& A, const auto& B) {
        int a = d[A][i], b = d[B][i];
        if(a == b and a == INF) return false;
        if(a == INF) return false;
        if(b == INF) return true;
        return a > b;
    };
    auto cmpfrom = [&](const auto& A, const auto& B) { 
        int a = d[i][A], b = d[i][B];
        if(a == b and a == INF) return false;
        if(a == INF) return false;
        if(b == INF) return true;
        return a > b;
    };

    for(i = 0; i < n; i++) {
        sort(to[i], to[i]+3, cmpto);
        sort(from[i], from[i]+3, cmpfrom);
        for(j = 3; j < n; j++) {
            if(!cmpto(to[i][0], j))
                to[i][2] = to[i][1], to[i][1] = to[i][0], to[i][0] = j;
            else if(!cmpto(to[i][1], j))
                to[i][2] = to[i][1], to[i][1] = j;
            else if(!cmpto(to[i][2], j))
                to[i][2] = j;
            if(!cmpfrom(from[i][0], j))
                from[i][2] = from[i][1], from[i][1] = from[i][0], from[i][0] = j;
            else if(!cmpfrom(from[i][1], j))
                from[i][2] = from[i][1], from[i][1] = j;
            else if(!cmpfrom(from[i][2], j))
                from[i][2] = j;
        }
    }


    int bestd = -1; array best{-1, -1, -1, -1};
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(d[i][j] == INF or i == j) continue;
            int t = 0, f = 0;
            if(to[i][t] == j or to[i][t] == i) t++;
            if(from[j][f] == i or from[j][f] == j) f++;
            if(to[i][t] != from[j][f]) {
                if(d[to[i][t]][i] == INF) continue;
                if(d[j][from[j][f]] == INF) continue;
                int res = d[to[i][t]][i] + d[i][j] + d[j][from[j][f]];
                if(chmax(bestd, res))
                    best = {to[i][t], i, j, from[j][f]};                
            } else {
                t++;
                if(to[i][t] == j or to[i][t] == i) t++;
                if(d[to[i][t]][i] < INF and d[j][from[j][f]] < INF) {
                    int res = d[to[i][t]][i] + d[i][j] + d[j][from[j][f]];
                    if(chmax(bestd, res))
                        best = {to[i][t], i, j, from[j][f]};                    
                }
                t--; f++;
                if(to[i][t] == j or to[i][t] == i) t--;
                if(from[j][f] == i or from[j][f] == j) f++;
                if(d[to[i][t]][i] < INF and d[j][from[j][f]] < INF) {
                    int res = d[to[i][t]][i] + d[i][j] + d[j][from[j][f]];
                    if(chmax(bestd, res))
                        best = {to[i][t], i, j, from[j][f]};                    
                }
            }
        }
    }

    for(i = 0; i < 4; i++)
        cout << best[i]+1 << " ";
}