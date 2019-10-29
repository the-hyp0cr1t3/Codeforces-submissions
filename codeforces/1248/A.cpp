#include <bits/stdc++.h>
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
#define ll long long

using namespace std;
const int N = 1e5 + 5;

struct mystruct {
    ll even, odd;
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i, m, a;
        ll count = 0;
        mystruct p, q;
        p.odd = p.even = q.odd = q.even = 0;
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> a;
            a & 1 ? p.odd++ : p.even++;
        }
        cin >> m;
        for(i = 0; i < m; i++) {
            cin >> a;
            a & 1 ? q.odd++ : q.even++;
        }
        count += p.even * q.even;
        count += p.odd * q.odd;
        cout << count << endl;
    }
    return 0;
}
