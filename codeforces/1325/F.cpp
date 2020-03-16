#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define rsz resize
#define pb emplace_back
#define sz(x) (int)(x).size()
const int N = 2e5 + 5;
int n, m, k = 1, d[N], par[N];
vector<int> g[N], indsets[N];

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void exitcycle(int fst, int lst) {
    cout << 2 << endl << d[fst] - d[lst] + 1 << endl;
    while(fst != lst) {
        cout << fst << " ";
        fst = par[fst];
    }
    cout << lst;
    exit(0);
}

void exitindset(int s) {
    cout << 1 << endl;
    indsets[s].rsz(k);
    for (auto& x: indsets[s]) 
        cout << x << " ";
    exit(0);
}

void dfs(int v, int kk) {
    d[v] = kk;
    for (auto x: g[v]) {
        if (d[x]) {
            if (d[x] < d[v] - 1 and d[v] - d[x] + 1 >= k)
                exitcycle(v, x);
            continue;
        }
        par[x] = v;
        dfs(x, kk+1);
    }
}

int32_t main() {
    IOS;
    int i;
    cin >> n >> m;
    while(k*k < n) k++;
    makeG();
    for(i = 1; i <= n; i++) 
        if(!d[i]) par[i] = -1, dfs(i, 1);

    for(i = 1; i <= n; i++) {
        int s = d[i] % (k-1);
        indsets[s].pb(i);
        if(sz(indsets[s]) >= k)
            exitindset(s);
    }
    
    assert(false);
    return 0;
}