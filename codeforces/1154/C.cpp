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
string s = "abcacbaabcacba";

int32_t main() {
    IOS;
    int i, a, b, c, d, ans = 0;
    cin >> a >> b >> c;
    d= min3(a/3, b/2, c/2);
    a -= 3*d;
    b -= 2*d;
    c -= 2*d;
    for(i = 0; i < 7; i++) {
        int x = a, y = b, z = c;
        for(int j = i; j < 13; j++) {
            if (s[j]=='a')
                x--;
            if (s[j]=='b')
                y--;
            if (s[j]=='c')
                z--;
            if (x < 0 or y < 0 or z < 0) {
                ans = max(ans, j-i);
                break;
            }
        }
    }
    ans += d*7;
    cout << ans;
    return 0;
}
