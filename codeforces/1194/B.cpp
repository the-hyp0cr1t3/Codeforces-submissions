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
#define Y second
#define X first
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int, int> pii;
const int N = 5e4 + 5;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, m, i, j, ans = 0;
        char c;
        cin >> n >> m;
        vector<int> row(n);
        vector<int> col(m);
        vector<vector<bool>> a(n, vector<bool>(m, 0)); 
        for(i = 0; i < n; i++) {
            for(j = 0; j < m; j++) {
                cin >> c;
                if (c=='*') {
                    a[i][j] = 1;
                    row[i]++, col[j]++;
                }
            }
        }
        for(i = 0; i < n; i++)
            for(j = 0; j < m; j++) 
                ans = max(ans, row[i]+col[j]-(a[i][j]==1));
        cout << n+m-1-ans << endl;
    }
    return 0;
}
