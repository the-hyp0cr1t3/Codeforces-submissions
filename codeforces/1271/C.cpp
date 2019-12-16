#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max4(x,y,z, w) max(max(x,w),max(y,z))
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

int32_t main() {
    IOS;
    int i, n, x, y, xi, yi, R, L, D, U;
    R = L = D = U = 0;
    cin >> n >> x >> y;
    for(i = 0; i < n; i++) {
        cin >> xi >> yi;
        if (xi > x) R++;
        if (xi < x) L++;
        if (yi > y) U++;
        if (yi < y) D++;
    }
    if (x == 0) L = -1;
    if (y == 0) D = -1;
    if (x == 1e9) R = -1;
    if (y == 1e9) U = -1;
    if (max4(R,L,D,U) == R) cout << R << endl << x+1 << " " << y;
    else if (max4(R,L,D,U) == L) cout << L << endl << x-1 << " " << y;
    else if (max4(R,L,D,U) == D) cout << D << endl << x << " " << y-1;
    else if (max4(R,L,D,U) == U) cout << U << endl << x << " " << y+1;
    return 0;
}