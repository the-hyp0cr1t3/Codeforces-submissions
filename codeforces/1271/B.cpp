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
const int N = 1e5 + 5;
vector<int> v, u;
vector<int> ans, ans2;
int32_t main() {
    IOS;
    int i, n;
    char a;
    cin >> n;
    v.rsz(n), u.rsz(n);
    for(i = 0; i < n; i++) {
        cin >> a;
        if (a == 'B') v[i] = 1;
        else u[i] = 1;
    }
    for(i = 0; i < n; i++) {
        if (v[i] and i < n-1)
            ans.pb(i+1), v[i+1]^=1;
        if (u[i] and i < n-1)
            ans2.pb(i+1), u[i+1]^=1;
    }
    if (v[n-1] and u[n-1]) {
        cout << -1;
        return 0;
    }
    if (!v[n-1]) {
        cout << ans.size() << endl;
        for (auto& x: ans) 
            cout << x << " ";
    }
    else {
        cout << ans2.size() << endl;
        for (auto& x: ans2) 
            cout << x << " ";
    }
    return 0;
}