#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define ins insert
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define lb lower_bound
#define ub upper_bound
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 2e5 + 5;
int n, m, k, a[N], off[N], cache[N], pre[N];

int dp (int idx) {
    if (idx == 0)
        return 0;
    int &ans = cache[idx];
    if (ans != -1)
        return ans;
    ans = INF;
    for(int i = 1; i <= idx; i++)
        ans = min(ans, pre[idx] - pre[idx - i + off[i]] + dp(idx-i));
    return ans;
}

int32_t main() {
    IOS;
    int i, x, y;
    memset(cache, -1, sizeof(cache));
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a+1, a+n+1);
    for(i = 1; i <= k; i++) 
        pre[i] = pre[i-1] + a[i];
    for(i = 1; i <= m; i++) {
        cin >> x >> y;
        off[x] = max(off[x], y);
    }
    cout << dp(k);
    return 0;
}
