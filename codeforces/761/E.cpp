#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define ff first
#define ss second
#define R 0
#define U 1
#define L 2
#define D 3
#define rsz resize
#define mp make_pair
#define pb push_back
#define sz(x) (int)(x).size()
typedef pair<ll, ll> pll;
const int N = 30 + 5;
const int MAXD = 59;
int n;
vector<int> g[N];
vector<bool> vis;
vector<pll> ans;

void makeG() {
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vis.rsz(n);
    ans.rsz(n);
}

void dfs(int v, ll x, ll y, int prv, int d) {
    vis[v] = 1;
    int dir = (prv+1)%4;
    ans[v] = mp(x, y);
    auto getx = [&] () {
        if (dir == U or dir == D) 
            return x;
        if (dir == R)
            return x+(1ll<<d);
        else
            return x-(1ll<<d);
    };
    auto gety = [&] () {
        if (dir == L or dir == R) 
            return y;
        if (dir == U)
            return y+(1ll<<d);
        else
            return y-(1ll<<d);
    };
    for (auto u: g[v]) {
        if (!vis[u]) {
            dfs(u, getx(), gety(), (dir+2)%4, d-1);
            dir++; dir %= 4;
        }
    }
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    makeG();
    for(i = 0; i < n; i++) 
        if (sz(g[i]) > 4) return cout << "NO", 0;
    dfs(0, 0, 0, -1, MAXD-1);
    cout << "YES" << endl;
    for (auto& x: ans) 
        cout << x.first << " " << x.second << endl;
    return 0;
}