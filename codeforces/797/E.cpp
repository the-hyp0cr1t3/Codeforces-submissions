#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
const int N = 1e5 + 5;
const int M = (int) sqrt(N) + 1;
int cache[N][M], a[N], n, k;

int dp (int p) {
    if (p > n)
        return 0;
    int &ans = cache[p][k];
    if (ans != -1)
        return ans;
    ans = 1 + dp(p+a[p]+k);
    return ans;
}

int32_t main() {
    IOS;
    memset(cache, -1, sizeof(cache));
    int i, Q;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    cin >> Q;
    while (Q--) {
        int p, ans = 0;
        cin >> p >> k;
        if (k >= M) {
            while(p <= n)
                p += a[p] + k, ans++;
        }
        else
            ans = dp(p);
        cout << ans << endl;
    }
    return 0;
}
