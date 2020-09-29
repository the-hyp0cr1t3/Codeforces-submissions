/**
 🍪 the_hyp0cr1t3
 🍪 29.09.2020 18:00:53
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
const int N = 2e5 + 5;
int indeg[N];

struct DSU {
    int n, components;
    vector<int> data, rootID, roots; 
    DSU(int n): n(n), components(n), data(vector<int>(n+1, -1)), 
        rootID(vector<int>(n+1, -1)) {}
    int par(int x) { return data[x] < 0 ? x : data[x] = par(data[x]); }
    int SZ(int x) { return -data[par(x)]; }
    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        components--;
        return true;
    }
    void getRoots() {
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(data[i] >= 0) continue;
            rootID[i] = cnt++;
            roots.pb(i);
        }
        assert(cnt == components);
    }
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m, ans = 0;
    cin >> n >> m;
    vector<vector<int>> g(n);
    DSU d(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        d.merge(--u, --v);
        g[u].pb(v);
        indeg[v]++;
    } d.getRoots();

    vector<vector<int>> components(d.components);
    for(i = 0; i < n; i++)
        components[d.rootID[d.par(i)]].pb(i);

    auto topsort = [&](vector<int>& nodes) {
        queue<int> q;
        int size = 0;
        for(auto& u: nodes)
            if(!indeg[u]) q.push(u);
        while(!q.empty()) {
            auto v = q.front();
            q.pop(); size++;
            for(auto& x: g[v]) 
                if(!--indeg[x]) q.push(x);
        } return sz(nodes) - (size == sz(nodes));
    };

    for(auto& v: components)
        ans += topsort(v);
    cout << ans << '\n';
}