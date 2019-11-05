#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

using namespace std;
const int N = 1e5 + 5;

int main() {
    IOS;
    int q;
    cin >> q;
    while (q--) {
        int n, i, m, c, x;
        cin >> c >> m >> x;
        cout << min(min(c, m), (c+m+x)/3) << endl;
    }
    return 0;
}
