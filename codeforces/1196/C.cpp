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
#define s second
#define f first
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
        int n, i, j, xi, yi, f;
        bool bad = 0;
        pii x = {-1e5, 1e5}, y = {-1e5, 1e5};
        cin >> n;
        for(j = 0; j < n; j++) {
            cin >> xi >> yi ;
            for(i = 0; i < 4; i++) {
                cin >> f;
                if (!f) {
                    if (i == 0) {
                        if (xi > x.s) bad = 1;
                        x.f = max(x.f, xi);
                    }
                    else if (i == 1) {
                        if (yi < y.f) bad = 1;
                        y.s = min(y.s, yi);
                    }
                    else if (i == 2) {
                        if (xi < x.f) bad = 1;
                        x.s = min(x.s, xi);
                    }
                    else {
                        if (yi > y.s) bad = 1;
                        y.f = max(y.f, yi);
                    }
                }
            }
        }
        if (bad) {
            cout << 0 << endl;
            continue;
        }
        cout << 1 << " " << x.f << " " << y.f << endl;
    }
    return 0;
}