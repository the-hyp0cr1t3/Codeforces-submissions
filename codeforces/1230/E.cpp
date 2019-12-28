#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define MOD 1000000007  //1e9 + 7
const int N = 1e5 + 5;
int a[N], n, ans = 0;
map <int,int> mp[N];

vector<int> g[N];

void makeG() {
    for(int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int v, int p) {
    mp[v][a[v]]++;
    mp[v][a[v]] %= MOD;
    ans += a[v];
    ans %= MOD;
    for (auto u: g[v]) {
        if (u == p) continue;
        for (auto& y: mp[v]) {
            int z = __gcd(a[u], y.ff);
            mp[u][z] += y.ss;
            mp[u][z] %= MOD;
            ans += z * y.ss;
            ans %= MOD;
        }
        dfs(u, v);
    }
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    makeG();
    dfs(1, -1);
    cout << ans;
    return 0;
}