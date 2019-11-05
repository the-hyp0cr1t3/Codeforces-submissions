#include <bits/stdc++.h>
//#define long int64_t
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
#define ll long long

using namespace std;
const int N = 2e5 + 5;

int main() {
    int i, n, s, a[N];
    ll ans = 0;
    cin >> n >> s;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    sort(a+1, a+n+1);
    if (a[n/2 + 1] > s) {
        for(i = 1; i <= n/2 + 1; i++) 
            ans += max(0, a[i] - s);
    }
    else {
        for(i = n/2 + 1; i <= n; i++)
            ans += max(0, s - a[i]);
    }
    cout << ans;
    return 0;
}
