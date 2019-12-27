#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 3e6 + 5;
int dp[N], n, root, sum = 0;
vector<int> g[N], ans;

void makeG() {
    for(int i = 1; i <= n; i++) {
        int v, t;
        cin >> v >> t;
        if (!v) root = i;
        g[v].pb(i);
        dp[i] = t;
        sum += t;
    }
}

void dfs(int v) {
    for (auto x: g[v]) {
        dfs(x);
        dp[v] += dp[x];
    }
    if (3*dp[v] == sum and v != root) ans.pb(v), dp[v] = 0;
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    makeG();
    dfs(root);
    if (sz(ans) >= 2) cout << ans[0] << " " << ans[1];
    else cout << -1;
    return 0;
}