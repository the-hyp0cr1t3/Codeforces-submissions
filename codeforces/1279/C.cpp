#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define ff first
#define ss second
#define rev(a) reverse(a.begin(),a.end())
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define lb lower_bound
#define ub upper_bound
#define rsz resize
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef pair<int, int> pii;
const int N = 1e5 + 5;
int a[N], b[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, m;
        ll ans = 0;
        cin >> n >> m;
        vector<int> vis(n+1, -1);
        for(i = 1; i <= n; i++) 
            cin >> a[i];
        for(i = 1; i <= m; i++) 
            cin >> b[i], vis[b[i]] = 0;
        int sofar = 0, j = 0;
        for(i = 1; i <= m; i++) {
            if (vis[b[i]] == 1) {
                ans++;
                continue;
            }
            for(j = j+1; j <= n; j++) {
                if (!vis[a[j]]) vis[a[j]] = 1;
                if (a[j] == b[i]) {
                    ans += 2*(j-i) + 1;
                    vis[a[j]] = 2;
                    break;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}