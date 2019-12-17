#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define rsz resize
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 5e3 + 5;
int n, m, k, a[N], b[N], c[N], last[N];
vector<vector<int>> capturepoints;
multiset <int> captured;
int32_t main() {
    IOS;
    int i, u, v;
    cin >> n >> m >> k;

    for(i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        last[i] = i;
    }

    for(i = 1; i <= m; i++) {
        cin >> u >> v; u--, v--;
        last[v] = max(last[v], u);
    }

    capturepoints.rsz(n);
    for(i = 0; i < n; i++)
        capturepoints[last[i]].pb(c[i]);

    for(i = 0; i < n; i++) {
        if (k < a[i])
            return cout << -1, 0;
        while (k - sz(captured) < a[i]) captured.erase(captured.begin());
        k += b[i];
        for (auto& x: capturepoints[i])
            captured.ins(x); 
    }

    int ans = 0;
    for (auto& x: captured) 
        ans += x;
    cout << ans;

    return 0;
}