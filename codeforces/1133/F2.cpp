#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define rsz resize
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, m, d, deg = 0, rem, candidate[N], vis[N];
vector<int> g[N];
vector<pii> ans;

void makeG() {
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if (!u or !v) deg++;
        g[u].pb(v);
        g[v].pb(u);
    }
    for (auto& x: g[0]) 
        candidate[x] = 1;
}

void dfs(int v) {
    vis[v] = 1;
    for (auto x: g[v]) {
        if (!vis[x]) {
            if (candidate[x]) {
                if (!rem) continue;
                rem--;
                dfs(x);
                vis[x] = 2;
            }
            else
                dfs(x);
            ans.pb({v, x});
        }
    }
}

int32_t main() {
    IOS;
    int i;
    cin >> n >> m >> d;
    makeG();    
    if (deg < d) return cout << "NO", 0;
    rem = deg - d;
    vis[0] = 1;
    for (auto& x: g[0]) 
        if (!vis[x]) dfs(x);
    if (rem) return cout << "NO", 0;
    for (auto& x: g[0])
        if (vis[x] == 1) ans.pb({0, x});
    cout << "YES" << endl;
    for (auto& x: ans) 
        cout << x.first+1 << " " << x.second+1 << endl;
    return 0;
}