#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define max(a,b) (a>b?a:b)
#define rsz resize
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int deg[N], n, m;
vector<int> g[N];
vector<bool> vis;

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++; deg[v]++;
    }
    vis.rsz(n);
}

void dfs(int v) {
    vis[v] = 1;
    for (auto x: g[v]) 
        if (!vis[x]) cout << v+1 << " " << x+1 << endl, dfs(x);
}

int32_t main() {
    IOS;
    int i, mx = -1, root;
    cin >> n >> m;
    makeG();
    for(i = 0; i < n; i++) 
        if (deg[i] > mx) mx = deg[i], root = i;
    vis[root] = 1;
    for (auto& x: g[root]) 
        cout << root+1 << " " << x+1 << endl, vis[x] = 1;
    for (auto& x: g[root]) 
        dfs(x);
    return 0;
}