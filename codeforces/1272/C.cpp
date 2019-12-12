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
int check[26];
int32_t main() {
    IOS;
    int i, n, k;
    string s;
    cin >> n >> k >> s;
    char c;
    memset(check, 0, sizeof(check));
    for(i = 0; i < k; i++) {
        cin >> c;
        check[c-'a'] = 1;
    }

    int prv = -1;
    ll ans = 0;
    for (i = 0; i < sz(s); i++) {
        if (!check[s[i]-'a']) {
            ans += 1ll*(i-prv-1)*(i-prv)/2;
            prv = i;
        }
    }
    ans += 1ll*(i-prv-1)*(i-prv)/2;
    cout << ans;
    return 0;
}