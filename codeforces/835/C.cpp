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
const int N1 = 10 + 5;
const int N2 = 100 + 5;
int cache[N1][N2][N2], n, q, c;

int32_t main() {
    IOS;
    int i, j, d, e, f;
    cin >> n >> q >> c;

    for(i = 0; i < n; i++) {
        cin >> d >> e >> f;
        for(j = 0; j < c+1; j++) 
            cache[j][d][e] += ((f+j) % (c+1));
    }

    for(int k = 0; k < 11; k++) {
        for(i = 1; i < 101; i++) {
            for(j = 1; j < 101; j++)
                cache[k][i][j] += cache[k][i][j-1] + cache[k][i-1][j] - cache[k][i-1][j-1];
        }
    }

    while (q--) {
        int t, x1, y1, x2, y2, ans = 0;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        t %= c+1;
        ans = cache[t][x2][y2] - cache[t][x1-1][y2] - cache[t][x2][y1-1] + cache[t][x1-1][y1-1];
        cout << ans << endl;
    }
    return 0;
}
