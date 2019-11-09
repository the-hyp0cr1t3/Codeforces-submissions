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
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define int long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 2e5 + 5;
int n, l, r, cache[N][3], a[3];

int dp (int idx, int sum) {
    if (idx == 1)
        return a[sum] % MOD;
    int &ans = cache[idx][sum];
    if (ans != -1)
        return ans;
    ans = 0;
    if (sum%3 == 0) {
        ans += (dp(idx-1, 0) * a[0]) % MOD;
        ans += (dp(idx-1, 1) * a[2]) % MOD;
        ans += (dp(idx-1, 2) * a[1]) % MOD;
        ans %= MOD;
    }
    else if (sum%3 == 1) {
        ans += (dp(idx-1, 0) * a[1]) % MOD;
        ans += (dp(idx-1, 1) * a[0]) % MOD;
        ans += (dp(idx-1, 2) * a[2]) % MOD;
        ans %= MOD;
    }
    else {
        ans += (dp(idx-1, 0) * a[2]) % MOD;
        ans += (dp(idx-1, 1) * a[1]) % MOD;
        ans += (dp(idx-1, 2) * a[0]) % MOD;
        ans %= MOD;
    }
    return ans;
}

int32_t main() {
    IOS;
    memset(cache, -1, sizeof(cache));
    int i;
    cin >> n >> l >> r;
    if ((r-l+1)%3 == 0)
        a[0] = a[1] = a[2] = (r-l+1)/3;
    else {
        i = (r-l+1)/3 + 1;
        a[l%3] = i;
        a[(l+2)%3] = i-1;
        a[(l+1)%3] = r-l+2-i-i;
    }
    cout << dp(n, 0);
    return 0;
}
