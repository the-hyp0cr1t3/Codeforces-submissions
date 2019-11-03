#include <bits/stdc++.h>
//#define long int64_t
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
const int N = 2e5 + 5;
int a[N], b[N], cache[N][2], n, c;

int dp (int idx, bool elev) {
    if (idx == 0)
        return 0;
    int &ans = cache[idx][elev];
    if (ans != -1)
        return ans;
    else {
        ans = dp(idx-1, 0) + a[idx];
        ans = min(ans, b[idx] + dp(idx-1, 1) + (elev^1)*c);
        return ans;
    } 
}

int32_t main() {
    int i;
    memset(cache, -1, sizeof(cache));
    cin >> n >> c;
    for(i = 1; i < n; i++) 
        cin >> a[i];
    for(i = 1; i < n; i++) 
        cin >> b[i];
    cout << 0 << " ";
    for(i = 1; i < n; i++) 
        cout << dp(i, 0) << " ";
    return 0;
}