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
#define sz(x) (int)(x).size()
#define X first
#define Y second
#define lb lower_bound
#define ub upper_bound
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> v;
set<int> ans;

bool check (int i) {
    for (auto& x: v)
        if ((x.X + i - 1)/i != x.Y) return 0;
    return 1;
}

int32_t main() {
    IOS;
    int i, n, m, l, r;
    cin >> n >> m;
    for(i = 0; i < m; i++) 
        cin >> l >> r, v.pb(mp(l,r));
    for(i = 1; i < 101; i++)
        if (check(i)) ans.ins((n+i-1)/i);
    if (sz(ans)==1)
        cout << *ans.begin();
    else
        cout << -1;
    return 0;
}
