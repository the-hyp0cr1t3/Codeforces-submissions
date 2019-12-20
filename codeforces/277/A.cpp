#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define rsz resize
#define pb push_back
#define sz(a) (int)(a).size()
const int N = 200 + 5;
int n, m, ans = 0;
vector<int> g[N];
vector<bool> vis;

void makeG() {
    bool nogood = 1;
    for(int i = 1; i <= n; i++) {
        int t, v;
        cin >> t;
        if (!t) ans++;
        while (t--) {
            nogood = 0;
            cin >> v;
            g[m+i].pb(v);
            g[v].pb(m+i);
        }
    }
    if (nogood) ans++;
}

void dfs(int v) {
    vis[v] = 1;
    for (auto x: g[v]) 
        if (!vis[x]) dfs(x);
}

int32_t main() {
    IOS;
    int i;
    cin >> n >> m;
    makeG();
    vis.rsz(n+m+2);
    for(i = 0; i <= n+m; i++)
        if (sz(g[i]) and !vis[i]) dfs(i), ans++;
    cout << ans-1;
    return 0;
}