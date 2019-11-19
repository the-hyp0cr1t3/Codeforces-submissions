#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define mp make_pair
#define pb push_back
typedef pair<int, int> pii;
const int N = 1e5 + 5;
int cnt[N] = {};
map <pii,vector<int>> adj;
vector<int> ans;
int32_t main() {
    IOS;
    int i, j, k, n, a, b, c;
    cin >> n;
    for(i = 0; i < n-2; i++) { 
        cin >> a >> b >> c;
        cnt[a]++, cnt[b]++, cnt[c]++;
        adj[mp(a,b)].pb(c);
        adj[mp(b,a)].pb(c);
        adj[mp(a,c)].pb(b);
        adj[mp(c,a)].pb(b);
        adj[mp(b,c)].pb(a);
        adj[mp(c,b)].pb(a);
    }
    for(i = 1; i <= n; i++) 
        if (cnt[i]==1) break;
    ans.pb(i);
    for(j = 1; j <= n; j++) 
        if (cnt[j] <= 2 and adj.count(mp(i,j))) break;
    ans.pb(j);
    k = adj[mp(i,j)][0];
    ans.pb(k);
    n -= 3;
    while(n--) {
        i = adj[mp(j,k)][0] ^ adj[mp(j,k)][1] ^ i;
        ans.pb(i);
        swap(i,k), swap(i,j);
    }
    for (auto& x: ans) 
        cout << x << " ";
    return 0;
}