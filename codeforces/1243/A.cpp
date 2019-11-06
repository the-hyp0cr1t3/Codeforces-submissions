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

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1000 + 5;

int main() {
    IOS;
    int q;
    cin >> q;
    while (q--) {
        int n, i, a, ans = 0;
        vector<int> v;
        cin >> n;
        for(i = 1; i <= n; i++) 
            cin >> a, v.pb(a);
        sort(v.begin(), v.end(), greater<int>());
        for(i = 0; i < n; i++) 
            ans = max(ans, min(i+1, v[i]));
        cout << ans << endl;
    }
    return 0;
}
