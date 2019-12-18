#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int cost[N];
map <pii,int> offers;

int32_t main() {
    IOS;
    int Q, n, i;
    cin >> n;
    ll ans = 0;
    for(i = 1; i <= n; i++) 
        cin >> cost[i], ans += cost[i];
    cin >> Q;
    while (Q--) {
        int s, t, u;
        cin >> s >> t >> u;
        if (offers.count({s,t})) {
            int v = offers[{s,t}];
            if (cost[v] >= 0) ans++;
            cost[v]++;
        }
        if (!u) {
            offers.erase({s,t});
            cout << ans << endl;
            continue;
        }
        offers[{s,t}] = u;
        if (cost[u] > 0) ans--;
        cost[u]--;
        cout << ans << endl;
    }
    return 0;   
}