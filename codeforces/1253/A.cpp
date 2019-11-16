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

int32_t main() {
    IOS;
    int Q;
    cin >> Q; 
    while (Q--) {
        int i, j, n, a[N], b[N], suma = 0, sumb = 0;
        bool flag = 0;
        cin >> n;
        set <int> s;
        for(i = 0; i < n; i++) 
            cin >> a[i];
        for(i = 0; i < n; i++) 
            cin >> b[i];
        bool flag1 = 0;
        for(j = n-1; j >= 0; j--) 
            if (a[j] != b[j]) break;
        for(i = 0; i < n; i++) {
            if (!flag1 and b[i] == a[i]) continue;
            flag1 = 1;
            if (b[i] - a[i] < 0) {
                flag = 1;
                break;
            }
            s.ins(b[i] - a[i]);
            if (i == j) flag1 = 0; 
        }
        if (sz(s)>1) flag = 1;
        if (flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
