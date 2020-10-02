/**
 🍪 the_hyp0cr1t3
 🍪 02.10.2020 20:14:35
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
const int N = 8e5 + 5;

int vis[2*N], comp[2*N], assignment[N];
vector<int> g[2*N], rg[2*N], order;

// p → q
void implies(int p, int q) {
    g[p].pb(q); rg[q].pb(p);
}

// p ∨ q
void Or(int p, int q) {
// (¬p → q) ∧ (¬q → p)
    implies(p^1, q); implies(q^1, p);
}

// p ⊕ q
void Xor(int p, int q) {
// (p ∨ q) ∧ (¬p ∨ ¬q)
    Or(p, q); Or(p^1, q^1);
}

// p ↔ q
void Biconditional(int p, int q) {
// (p → q) ∧ (q → p) ≡ (p ⊕ ¬q)
    Xor(p, q^1);
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
        assignment[i] = comp[i<<1] > comp[i<<1|1];
    } return true;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, p, fmax, m;
    cin >> n >> p >> fmax >> m;
    for(i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        Or(--x<<1, --y<<1);
    }
    for(i = 0; i < p; i++) {
        int l, r; cin >> l >> r;
        Or(i<<1|1, p+l-1<<1);
        Or(i<<1|1, p+r<<1|1);
    }
    for(i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        Or(--x<<1|1, --y<<1|1);
    }
    for(i = 0; i+1 < fmax; i++)
        Or(p+i<<1, p+i+1<<1|1);

    if(!is_sat(p+fmax)) return cout << -1, 0;

    int k = 0, f = -1;
    for(i = 0; i < p; i++)
        if(assignment[i]) k++;
    for(i = 0; i < fmax; i++)
        if(assignment[p+i]) f = i+1;

    assert(~f);
    cout << k << ' ' << f << '\n';
    for(i = 0; i < p; i++)
        if(assignment[i]) cout << i+1 << ' ';    
}