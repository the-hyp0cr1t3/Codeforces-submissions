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
#define int long long
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 300 + 5;
int d[N];
set<int> divs;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i;
        int ans;
        bool flag = 0;
        cin >> n;
        for(i = 0; i < n; i++) 
            cin >> d[i];
        sort(d, d+n);
        ans = d[0]*d[n-1];
        for(i = 2; i*i <= ans; i++) 
            if (ans%i == 0)
                divs.ins(i), divs.ins(ans/i);
        i = 0;
        for (auto& x: divs) {
            if (i >= n or x != d[i++]) {
                flag = 1;
                break;
            }
        } 
        if (flag)
            cout << -1 << endl;
        else
            cout << ans << endl;
        divs.clear();
    }
    return 0;
}
