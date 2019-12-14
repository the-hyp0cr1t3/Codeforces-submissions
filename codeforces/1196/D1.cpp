#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define Y second
#define X first
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int, int> pii;
const int N = 2e5 + 5;
int dp[N][3];
string t = "RGB";
//sadsa
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        memset(dp, 0, sizeof(dp));
        int n, i, j, k, ans = INF;
        string s;
        cin >> n >> k >> s;
        for(i = 0; i < k; i++) {
            for(j = 0; j < 3; j++) 
                dp[0][j] += (s[i] != t[(j+i)%3]);
        }
        for(i = 0; i < 3; i++) 
            ans = min(ans, dp[0][i]);
        int l, r;
        for(l = 0, r = k; r < n; l++, r++) {
            for(j = 0; j < 3; j++) {
                dp[l+1][j] = dp[l][(j+2)%3] - (s[l] != t[(j+2)%3]) + (s[r] != t[(j+k-1)%3]);
                ans = min(ans, dp[l+1][j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}