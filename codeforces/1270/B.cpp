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
const int N = 2e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, mx = 0, mn = INF, mxi, mni, l = -1, r = -1;
        cin >> n;
        for(i = 1; i <= n; i++) {
            cin >> a[i]; 
            if (a[i] < mn)mn = a[i], mni = i;
            if (a[i] > mx)mx = a[i], mxi = i;
            if (i > 1) {
                if (abs(a[i]-a[i-1]) >= 2)
                    l = i-1, r = i;
            }
        }
        if (l == -1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            cout << l << " " << r << endl;
        }
    }
    return 0;
}