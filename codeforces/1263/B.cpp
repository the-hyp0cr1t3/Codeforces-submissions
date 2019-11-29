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

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, p, j, k, cnt, ans = 0;
        string t;
        set <string> s;
        vector<string> v, rem, u;
        cin >> n;
        vector<bool> vis(n);
        for (i = 0; i < n; i++) {
            cin >> t;
            p = sz(s);
            s.ins(t);
            if (sz(s) != p) {
                v.pb(t);
                vis[i] = 1;
                continue;
            }
            rem.pb(t);
        }
        p = sz(s);
        for (auto& x: rem) {
            ans++;
            j = 0, cnt = 0;
            while(sz(s)==p) {
                char c = x[j];
                c = (char)((c - '0' + 1) % 10 + '0');
                x[j] = c;
                if (cnt == 9) {
                    j++;
                    c = (char)((c - '0' + 1) % 10 + '0');
                    x[j] = c;
                }
                s.ins(x);
                cnt++;
            }
            u.pb(x);
            p = sz(s);
        }
        cout << ans << endl;
    
        for(i = 0, j = 0, k = 0; i < n; i++) {
            if (vis[i] and j < sz(v)) 
                cout << v[j++] << endl;
            else
                cout << u[k++] << endl;
        }
    }
    return 0;
}