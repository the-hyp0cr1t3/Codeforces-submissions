#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define popb pop_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
const int N = 2e4 + 5;
int n, m, cnt, deg[N];
vector<int> g[N];
vector<pii> ans;

void makeG() {
    for(int i = 0; i <= n; i++) 
        g[i].clear(), deg[i] = 0;
    ans.clear();
    cnt = 0;
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
        deg[u]++; deg[v]++;
    }
    for(int i = 1; i <= n; i++) {
        if (deg[i] & 1) {
            g[i].pb(0);
            g[0].pb(i);
            cnt++;
        }
    }
}

void dfs(int v) {
    while (sz(g[v])) {
        int x = g[v].back();
        g[v].popb();
        g[x].erase(find(all(g[x]), v));
        if (v and x)
            ans.pb({v, x});
        dfs(x);
    }
}

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int i;
        cin >> n >> m;
        makeG();
        for(i = 0; i <= n; i++) 
            dfs(i);
        cout << n - cnt << endl;
        for (auto& x: ans) 
            cout << x. first << " " << x.second << endl;
    }
    return 0;
}