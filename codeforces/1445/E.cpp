/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 19:14:45
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
#include <ext/pb_ds/assoc_container.hpp>

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const pair<int, int>& x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x.second + FIXED_RANDOM) ^ (splitmix64(FIXED_RANDOM + x.first) << 1);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};


struct edge_t {
    int u, v;
    edge_t() = default;
    edge_t(int u, int v) : u(u), v(v) {}
};

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 5e5 + 5;
int c[N], col[N], newcol[N], badgrp[N];
array<int, 2> head[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> groups(k);
    for(i = 0; i < n; i++) {
        cin >> c[i];
        col[i] = head[i][0] = head[i][1] = -1;
        groups[--c[i]].pb(i);
    }

    vector<vector<int>> singles(n);
    __gnu_pbds::gp_hash_table<pair<int, int>, vector<edge_t>, custom_hash> edges;
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if(c[--u] > c[--v]) swap(u, v);
        if(c[u] == c[v])
            singles[u].pb(v), singles[v].pb(u);
        else
            edges[{c[u], c[v]}].pb(u, v);
    }
    
    auto dfs1 = Y([&](auto self, array<int, 2>& r, int v, int d = 0) -> void {
        col[v] = d; r[d] = v;
        for(auto& x: singles[v]) {
            if(col[x] == -1)
                self(r, x, d^1);
            else if(col[x] == d)
                badgrp[c[v]] = 1;
        }
    });

    auto dfs2 = Y([&](auto self, array<int, 2>& r, int v) -> void {
        head[v] = r;
        for(auto& x: singles[v])
            if(head[x] == array{-1, -1}) self(r, x);
    });

    for(auto& grp: groups) {
        for(auto& x: grp) {
            if(~col[x]) continue;
            array<int, 2> r{-1, -1};
            dfs1(r, x); dfs2(r, x);
        }
    }

    int64_t ans = 0;
    for(i = 0; i < k; i++) if(!badgrp[i]) ans++;
    ans = ans * (ans-1) / 2;

    auto dfs3 = Y([&](auto self, int v, auto& g, int d = 0) -> bool {
        newcol[v] = d; bool ok = true;
        for(auto& x: g[v]) {
            if(newcol[x] == -1)
                ok &= self(x, g, d^1);
            else if(newcol[x] == d)
                ok = false;
        } return ok;
    });

    auto good = [&](int a, int b, vector<edge_t>& ed) {
        bool ok = true;
        __gnu_pbds::gp_hash_table<int, vector<int>, custom_hash> g;
        vector<int> nodes;
        for(auto& e: ed) {
            e.u = head[e.u][col[e.u]]; e.v = head[e.v][col[e.v]];
            if(~newcol[e.u]) nodes.pb(e.u);
            if(~newcol[e.v]) nodes.pb(e.v);
            if(~head[e.u][col[e.u]^1] and ~newcol[head[e.u][col[e.u]^1]]) {
                nodes.pb(head[e.u][col[e.u]^1]);
                g[e.u].pb(head[e.u][col[e.u]^1]);
                g[head[e.u][col[e.u]^1]].pb(e.u);
                newcol[head[e.u][col[e.u]^1]] = -1;
            }
            if(head[e.v][col[e.v]^1] and ~newcol[head[e.v][col[e.v]^1]]) {
                nodes.pb(head[e.v][col[e.v]^1]);
                g[e.v].pb(head[e.v][col[e.v]^1]);
                g[head[e.v][col[e.v]^1]].pb(e.v);
                newcol[head[e.v][col[e.v]^1]] = -1;
            }
            newcol[e.u] = newcol[e.v] = -1;
            g[e.u].pb(e.v); g[e.v].pb(e.u);
        }
        for(auto& x: nodes)
            if(newcol[x] == -1) ok &= dfs3(x, g);
        return ok;
    };

    for(auto& [cols, es]: edges) {
        auto [x, y] = cols;
        if(badgrp[x] or badgrp[y]) continue;
        if(!good(x, y, es)) ans--;
    } cout << ans << '\n';
}