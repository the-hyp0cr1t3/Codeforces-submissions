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

bool valid (char c) {
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u')
        return 0;
    else
        return 1;
}

int32_t main() {
    IOS;
    int i, n, cnt = 0, mark = 0;
    string s, ans;
    cin >> s;
    for(i = 0; i < sz(s); i++) {
        if (valid(s[i])) {
            cnt++;
            mark |= (1<<s[i]-'a');
            if (cnt >= 3 and __builtin_popcount(mark)!=1)
                ans += " ", cnt = 1, mark = (1<<s[i]-'a');
            ans += s[i];
        }
        else {
            ans += s[i];
            cnt = 0;
            mark = 0;
        }
    }
    cout << ans;
    return 0;
}
