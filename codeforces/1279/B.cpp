#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
#define cerr if(1)cerr
#define watch(x) cerr << (#x) << " is " << (x) << " "
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
const int N = 2e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, j, s, mx = 0;
        bool flag = 0;
        int q = 0;
        int ans = 0, sum = 0;
        cin >> n >> s;
        for(i = 1; i <= n; i++) 
            cin >> a[i];
        for(i = 1; i <= n; i++) {
            sum += a[i];
            if (sum - q > s and i != 1) break;
            if (sum > s) flag = 1;
            if (a[i] > q) q = a[i], mx = i;
        }
        if (i == n+1 and sum <= s) {
            cout << 0 << endl;
            continue;
        }
        if (sum - a[mx] > s and !flag) mx = i;
        cout << mx << endl;
    }
    return 0;
}