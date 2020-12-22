/**
 🍪 the_hyp0cr1t3
 🍪 02.10.2020 16:27:29
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
const int N = 1e5 + 5;

int vis[2*N], comp[2*N];
vector<int> g[2*N], rg[2*N], order;

// (p ∨ q) meaning at least one is true
void addedge(int p, int q) {
// (¬p → q) ∧ (¬q → p)
    g[p^1].pb(q); g[q^1].pb(p);
    rg[q].pb(p^1); rg[p].pb(q^1);
}

// (p ⊕ q) meaning exactly one is true
void xoredge(int p, int q) {
// (p ∨ q) ∧ (¬p ∨ ¬q)
    addedge(p, q); addedge(p^1, q^1);
}

// (p ↔ q) both are true or both are false
void biconditionaledge(int p, int q) {
// (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)
    xoredge(p, q^1);
}

void dfs1(int v) {
    vis[v] = 1;
    for(auto& x: g[v])
        if(!vis[x]) dfs1(x);
    order.pb(v);
}

void dfs2(int v, int k) {
    comp[v] = k;
    for(auto& x: rg[v])
        if(comp[x] == -1) dfs2(x, k);
}

bool is_sat(int n) {
    memset(comp, -1, sizeof(comp));
    order.reserve(2*n);
    for(int i = 0; i < 2*n; i++)
        if(!vis[i]) dfs1(i);

    reverse(all(order));
    int sccnt = 0;
    for(auto& v: order)
        if(comp[v] == -1)
            dfs2(v, sccnt++);

    for(int i = 0; i < n; i++) {
        if(comp[i<<1] == comp[i<<1|1]) return false;
    } return true;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> n >> m;
    vector<int> unlocked(n);
    for(i = 0; i < n; i++)
        cin >> unlocked[i];

    vector<vector<int>> switches(n);
    for(i = 0; i < m; i++) {
        int t; cin >> t;
        while(t--) {
            int r; cin >> r;
            switches[--r].pb(i);
        }
    }

    for(i = 0; i < n; i++) {
        int u = switches[i][0];
        int v = switches[i][1];
        if(unlocked[i])
            biconditionaledge(u<<1, v<<1);
        else
            xoredge(u<<1, v<<1);
    }

    cout << (is_sat(m)? "YES" : "NO") << '\n';
}