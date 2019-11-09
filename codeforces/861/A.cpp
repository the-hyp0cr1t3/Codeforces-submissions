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

map<int, int> factorize(int x)
{
    int n = x;
    map<int, int> m;
    for(int i = 2; i*i <= n and x > 1; ++i)
        while(x % i == 0)
            m[i]++, x /= i;
    if(x > 1)
        m[x]++;
    return m;
}

int32_t main() {
    IOS;
    int i, n, t;
    ll ans = 1;
    cin >> n >> t;
    map <int,int> m = factorize(n);
    for (auto& [k, v]: m) {
        if (k == 2 or k == 5)
            v = max(0, v-t);
        for(i = 0; i < v; i++) 
            ans *= k;
    }
    cout << ans;
    for(i = 0; i < t; i++) 
        cout << 0;
    return 0;
}