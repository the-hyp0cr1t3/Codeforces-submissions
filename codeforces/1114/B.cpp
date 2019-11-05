#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 100000007  //1e8 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define ins insert
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

using namespace std;
const int N = 2e5 + 5;

int main() {
    IOS;
    int i, n, m, k, a[N], cnt = 0;
    ll sum = 0;
    multiset <int> s;
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) 
        cin >> a[i], sum += a[i], s.ins(a[i]);
    for(i = 0; i < n - m*k; i++) 
        sum -= *s.begin(), s.erase(s.begin());
    cout << sum << endl;
    for(i = 1; i <= n; i++) {
        auto pos = s.find(a[i]);
        if ( pos != s.end()) {
            cnt++;
            s.erase(pos);
            if (cnt%m == 0 and cnt < m*k)
                cout << i << " ";
        }
    }
    return 0;
}
