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
#define int long long
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 5;

int32_t main() {
    IOS;
    int i, n, prv = -1, cnt = 0, ans = 0;
    bool flag = 0;
    string s;
    cin >> n >> s;
    for(flag = 0, i = 0; i < n; i++)  {
        if (s[i] == 'A' and !flag)
            flag = 1, prv = i;
        if (s[i] == 'A' and flag)
            ans += max(0, i-prv-1), prv = i, cnt = 0;
        if (s[i] == 'B' and flag)
            cnt++;
    }
    if (cnt) ans += max(0, i-prv-1);
    for(cnt = 0, flag = 0, i = 0; i < n; i++)  {
        if (s[i] == 'B' and !flag)
            flag = 1, prv = i;
        if (s[i] == 'B' and flag)
            ans += max(0, i-prv-1), prv = i;
        if (s[i] == 'A' and flag)
            cnt++;
    }
    if (cnt) ans += max(0, i-prv-1);
    reverse(s.begin(), s.end());
    for(cnt = 0, flag = 0, i = 0; i < n; i++)  {
        if (s[i] == 'B' and !flag)
            flag = 1, prv = i;
        if (s[i] == 'B' and flag)
            ans += max(0, i-prv-2), prv = i;
        if (s[i] == 'A' and flag)
            cnt++;
    }
    if (cnt) ans += max(0, i-prv-2);
    for(cnt = 0, flag = 0, i = 0; i < n; i++)  {
        if (s[i] == 'A' and !flag)
            flag = 1, prv = i;
        if (s[i] == 'A' and flag)
            ans += max(0, i-prv-2), prv = i;
        if (s[i] == 'B' and flag)
            cnt++;
    }
    if (cnt) ans += max(0, i-prv-2);
    ans = n*(n-1)/2 - ans;
    cout << ans;
    return 0;
}
