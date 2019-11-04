#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define int long long

using namespace std;
const int N = 1e5 + 5;

int32_t main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, a, b, s;
        cin >> a >> b >> n >> s;
        if ((s/n <= a and s%n <= b))
            cout << "YES" << endl;
        else if (a*n < s and (b >= s - a*n))
            cout << "YES" << endl;
        else
            cout << "NO" <<endl;
    }
    return 0;
}
