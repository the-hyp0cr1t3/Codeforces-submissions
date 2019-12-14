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
const int N = 1e5 + 5;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, j, k, a, cnt = 0;
        vector<int> ans;
        cin >> n >> k;
        for(i = 1, j = 0; i <= n; i++) {
            cin >> a;
            if (j == k-1 and a&1) cnt++;
            if (j < k-1 and a&1) ans.pb(i), j++;
        }
        if (j < k-1 or cnt%2==0)
            cout << "NO" << endl;
        else {
            ans.pb(n);
            cout << "YES" << endl;
            for (auto& x: ans) 
                cout << x << " ";
            cout << endl;
        }
    }
    return 0;
}