#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
#define X first
#define Y second
#define lb lower_bound
#define ub upper_bound
#define ll long long
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1e5 + 5;

int factor (int x) {
    int i; bool flag = 0;
    for(i = 2; i*i <= x; i++) 
        if (x%i == 0) {
            flag = 1;
            break;
        }
    if (flag) return i;
    else return -1;
}

int32_t main() {
    IOS;
    int i, n, k, x;
    cin >> n >> k;
    vector<int> ans;
    if (k == 1)
        return cout << n, 0;
    while (k>1) {
        x = factor(n);
        if (x == -1)
            return cout << -1, 0;
        else
            ans.pb(x), n = n/x;
        k--;
    }
    ans.pb(n);
    for (auto& x: ans) 
        cout << x << " ";
    return 0;
}
