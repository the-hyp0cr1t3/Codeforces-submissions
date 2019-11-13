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
const int N = 2e5 + 5;
pair<int, int> a[N];
bool visited[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        memset(visited, 0, sizeof(visited));
        int n, i, b;
        cin >> n;
        for(i = 0; i < N; i++) 
            a[i].X = a[i].Y = 0;
        for(i = 1; i <= n; i++) {
            cin >> b;
            if (visited[b]) {
                if (i - a[b].Y < a[b].X) a[b].X = i - a[b].Y;
                a[b].Y = i;
            }
            else {
                a[b].X = INF, a[b].Y = i;
                visited[b] = 1;
            }
        }
        int ans = INF;
        for(i = 0; i < N; i++) 
            if (a[i].X)
                ans = min(a[i].X, ans);
        cout << (ans==INF? -1 : ans+1) << endl;
    }
    return 0;
}
