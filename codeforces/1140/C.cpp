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
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 3e5 + 5;
pair<int, int> a[N];

bool Comparator (pair <int, int> x, pair <int, int> y) {
    if (x.ff == y.ff)
        return x.ss < y.ss;
    return x.ff < y.ff;
}

int main() {
    IOS;
    int i, n, k;
    ll ans = 0, sum = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++)
        cin >> a[i].ss >> a[i].ff;
    sort(a, a+n, Comparator);
    multiset <int> s;
    for(i = n-1; i >= 0; i--) {
        sum += a[i].ss;
        s.ins(a[i].ss);
        ans = max(ans, sum*a[i].ff);
        if ((int)s.size() >= k)
            sum-=*s.begin(), s.erase(s.begin());
    }
    cout << ans;
    return 0;
}
