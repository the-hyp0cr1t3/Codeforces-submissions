#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define rsz resize
#define pb push_back
const int N = 1e5 + 5;
int n;
vector<int> g[N], ans, vis;

void makeG() {
    for(int i = 0; i < n; i++) {
        int u, t;
        cin >> t;
        while (t--) {
            cin >> u;
            u--;
            g[i].pb(u);
        }
    }
    vis.rsz(n);
}

void dfs(int v) {
    vis[v] = 1;
    for (auto x: g[v]) {
        if (vis[x] == 1)
            cout << -1, exit(0);
        if (!vis[x]) dfs(x);
    }
    vis[v] = 2;
    ans.pb(v);
}

int32_t main() {
    IOS;
    int i, a, k;
    cin >> n >> k;
    stack <int> s;
    while (k--)
        cin >> a, s.push(a-1);
    makeG();
    while(!s.empty()) {
        if (!vis[s.top()]) dfs(s.top());
        s.pop();
    }
    cout << ans.size() << endl;
    for (auto& x: ans) 
        cout << x+1 << " ";
    return 0;
}