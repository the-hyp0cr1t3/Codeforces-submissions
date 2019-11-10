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
const int N = 2e6 + 5;
const int MaxGCD = 1e7 + 5;

int32_t main() {
    IOS;
    int i, n, a[N], A = -1, B = -1, loc[MaxGCD] = {};
    ll lcm = DESPACITO, x, y;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        if (loc[a[i]] and a[i] < lcm)
            A = loc[a[i]], B = i, lcm = a[i];
        else
            loc[a[i]] = i;
    }
    
    for(ll gcd = 1; gcd < MaxGCD; gcd++) {
        x = 0, y = 0;
        for(ll j = gcd; j < MaxGCD; j+=gcd) {
            if (loc[j]) {
                if (x) {
                    y = j;
                    break;
                }
                else
                    x = j;
            }
        }
        if (x and y) {
            ll lmao = x*y/gcd;
            if (lmao < lcm) {
                lcm = lmao;
                A = loc[x];
                B = loc[y];
                //watch(A);
                if (A>B)
                    swap(A,B);
            }
        }
    }
    cout << A << " " << B;
    return 0;
}
