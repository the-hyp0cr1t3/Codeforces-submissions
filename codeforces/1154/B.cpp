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
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1e5 + 5;

int32_t main() {
    IOS;
    int i, n, a, q, ans;
    bool flag = 0;
    set <int> s;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        s.ins(a);
        if (sz(s) > 3)
            flag = 1;
    }
    if (flag)
        return cout << -1, 0;
    if (sz(s)==3) {
        auto it1 = s.begin();
        auto it2 = s.begin();
        it1++;
        it2++;
        it2++;
        if ((*s.begin()+*it2) & 1)
            return cout << -1, 0;
        if ((*s.begin()+*it2)/2 != *it1)
            return cout << -1, 0;
        ans = *it2 - *it1;
    }
    if (sz(s)==2) {
        auto it1 = s.begin();
        it1++;
        if ((*s.begin()+*it1) & 1)
            ans = *it1 - *s.begin();
        else
            ans = *it1 - (*it1 + *s.begin())/2;
    }
    if (sz(s)==1)
        ans = 0;
    cout << ans;
    return 0;
}
