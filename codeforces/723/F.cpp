#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define S 0
#define T 1
#define ff first
#define ss second
#define pb push_back
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int s, t, ds, dt;
bool bad = 0, common = 0, ST = 0;
vector<pii> ans;
vector<int> edges[N], toRoot[2];

struct DSU {
    int n, parent[N], node[N], roots[N], rootID[N], rootcnt;
    DSU (int Q) : n(Q) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            node[i] = 1;
            rootcnt = 0;
            rootID[i] = -1;
            roots[i] = -1;
        }
    }
    int findparent (int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findparent(parent[x]);
    }
    void merge (int a, int b) {
        int x = findparent(a);
        int y = findparent(b);
        if (x == y) return;
        if (node[x] > node[y]) swap(x, y);
        parent[y] = x, node[x] += node[y];
        ans.pb({a, b});
    }
    bool same (int x, int y) {
        return findparent(x) == findparent(y);
    }
    bool only (int x) {
        return node[findparent(x)] == 1;
    }
    void getRoots () {
        for(int i = 0; i < n; i++) {
            if (parent[i] != i or i == s or i == t) continue;
            rootID[i] = rootcnt;
            roots[rootcnt++] = i;
        }
        toRoot[S].assign(rootcnt, -1);
        toRoot[T].assign(rootcnt, -1);
    }
};

int32_t main() {
    IOS;
    int i, n, m;
    cin >> n >> m;
    DSU g(n);
    for(i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        edges[u].pb(v);
        edges[v].pb(u);
    }
    cin >> s >> t >> ds >> dt;
    s--; t--;

    for(i = 0; i < n; i++) {
        if (i == s or i == t) continue;
        for (auto& x: edges[i]) {
            if (x == s or x == t) continue;
            g.merge(x, i);
        }
    }

    g.getRoots();
    
    for (auto& x: edges[s]) {
        if (x == t) {
            ST = 1;
            continue;
        }
        int z = g.rootID[g.findparent(x)];
        if (toRoot[S][z] == -1)
            toRoot[S][z] = x;
    }

    for (auto& x: edges[t]) {
        if (x == s) continue;
        int z = g.rootID[g.findparent(x)];
        if (toRoot[T][z] == -1)
            toRoot[T][z] = x;
    }
    
    for(i = 0; i < g.rootcnt; i++) {
        if (toRoot[S][i] == -1 and toRoot[T][i] == -1)
            bad = 1;
        if (toRoot[S][i] == -1) {
            dt--;
            ans.pb({toRoot[T][i], t});
        }
        else if (toRoot[T][i] == -1) {
            ds--;
            ans.pb({toRoot[S][i], s});
        }
        else
            common = 1;
    }

    if (!common and !ST)
        bad = 1;

    if (!common) {
        ds--; dt--;
        ans.pb({s, t});
    }
    else {
        bool first = 1;
        for(i = 0; i < g.rootcnt; i++) {
            if (toRoot[S][i] == -1 or toRoot[T][i] == -1)
                continue;
            if (first) {
                ds--; dt--;
                ans.pb({toRoot[S][i], s});
                ans.pb({toRoot[T][i], t});
                first = 0;
            }
            else {
                if (ds > 0)
                    ds--, ans.pb({toRoot[S][i], s});
                else
                    dt--, ans.pb({toRoot[T][i], t});
            }
        }
    }

    if (ds < 0 or dt < 0) 
        bad = 1;

    if (bad)
        cout << "No";
    else {
        cout << "Yes" << endl;
        for (auto& x: ans) 
            cout << x.ff+1 << " " << x.ss+1 << endl;
    }
    return 0;
}