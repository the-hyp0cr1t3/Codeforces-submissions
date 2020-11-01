/**
 🍪 the_hyp0cr1t3
 🍪 02.11.2020 00:20:33
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, k;
    cin >> n >> m >> k;
    
    vector<int> c(n), ok(k, 1);
    for(auto& x: c) cin >> x, --x;

    vector<int> data(n, -1), val(n);
    auto get_par = [&](int u) -> array<int, 2> {
        int x = u, v = 0;
        while(data[x] >= 0) {
            v ^= val[x];
            x = data[x];
        } return {x, v};
    };

    vector<pair<int*, int>> magic; magic.reserve(3*m);
    auto merge = [&](int u, int v, bool rollback = false) {
        auto [a, x] = get_par(u);
        auto [b, y] = get_par(v);
        if(a == b) {
            return x ^ y;
        } else {
            if(-data[a] < -data[b]) swap(a, b), swap(x, y);
            if(rollback) {
                magic.pb(&data[a], data[a]);
                magic.pb(&data[b], data[b]);
                magic.pb(&val[b], val[b]);                
            } data[a] += data[b]; data[b] = a; val[b] = x^y^1;
            return 1;
        }
    };

    vector<array<int, 2>> edges; edges.reserve(m);
    for(i = 0; i < m; i++) {
        int u; int v; cin >> u >> v;
        if(c[--u] > c[--v]) swap(u, v);
        if(c[u] == c[v]) ok[c[u]] &= merge(u, v);
        else edges.pb(array{u, v});
    }

    sort(all(edges), [&](const auto& A, const auto& B) { 
        return array{c[A[0]], c[A[1]]} < array{c[B[0]], c[B[1]]}; 
    });

    int64_t ans = accumulate(all(ok), 0);
    ans = ans * (ans-1) / 2;

    for(i = j = 0; i < sz(edges); i = j) {
        while(j < sz(edges) and c[edges[i][0]] == c[edges[j][0]]
            and c[edges[i][1]] == c[edges[j][1]]) j++;
        if(!ok[c[edges[i][0]]] or !ok[c[edges[i][1]]]) continue;
        bool good = true;
        while(i < j) good &= merge(edges[i][0], edges[i][1], true), i++;
        if(!good) ans--;
        while(!magic.empty()) *magic.back().first = magic.back().second, magic.pop_back();
    }

    cout << ans;
}