#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define all(a) a.begin(),a.end()
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 1e5 + 5;
vector<int> g[N];
vector<int> ans;
int n, root, c[N];

void makeG() {
    for(int i = 0; i < n; i++) {
        int par;
        cin >> par >> c[i];
        if (par == -1) {
            root = i;
            continue;
        }
        par--;
        g[par].pb(i);
    }
}

void dfs(int v, bool k) {
    k = c[v];
    bool bad = 0;
    for (auto& x: g[v]) {
        if (k and !c[x]) bad = 1;
        dfs(x, k);
    }
    if (!bad and k) ans.pb(v);
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    makeG();
    dfs(root, 0);
    if (!sz(ans)) return cout << -1, 0;
    sort(all(ans));
    for (auto& x: ans) 
        cout << x+1 << " ";
    return 0;
}