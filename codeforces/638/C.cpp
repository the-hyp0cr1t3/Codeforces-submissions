#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define ff first
#define ss second
#define mp make_pair
#define rsz resize
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int n, a[N], k = 0;
vector<pii> g[N];
vector<bool> vis;
vector<int> ans[N];

void makeG() {
    for(int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(mp(v, i));
        g[v].pb(mp(u, i));
    }
    vis.rsz(n);
}

void dfs(int v) {
    vis[v] = 1;
    int d = 0;
    for (auto x: g[v]) {
        if (!vis[x.ff]) {
            if (d == a[v]) d++;
            a[x.ff] = d++;
            dfs(x.ff);
        }
        else
            ans[a[v]].pb(x.ss);
    }
    k = max(k, d);
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    makeG();
    a[0] = -1;
    dfs(0);
    cout << k << endl;
    for(i = 0; i < k; i++) {
        cout << sz(ans[i]) << " ";
        for (auto& x: ans[i]) 
            cout << x << " ";
        cout << endl;
    }
    return 0;
}