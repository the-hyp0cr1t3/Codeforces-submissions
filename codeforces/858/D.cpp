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
const int N = 70000 + 5;

int32_t main() {
    IOS;
    int i, n, l, r;
    string s[N];
    map <string,int> substrings;
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> s[i];
        string sub;
        for(l = 0; l < sz(s[i]); l++) {
            for(r = 1; r <= sz(s[i]) - l; r++) {
                sub = s[i].substr(l, r);
                substrings[sub] = substrings[sub]? substrings[sub]==i? i : -1 : i;
            }
        }
    }
    for(i = 1; i <= n; i++) {
        string sub;
        string ans = s[i];
        for(l = 0; l < sz(s[i]); l++) {
            for(r = 1; r <= sz(s[i]) - l; r++) {
                sub = s[i].substr(l, r);
                if (substrings[sub] != -1) {
                    if (sz(sub) <= sz(ans))
                        ans = sub;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
