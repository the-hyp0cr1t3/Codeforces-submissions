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
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 1e3 + 5;

int main() {
    IOS;
    int i, j, n, a[N], ans, mincost = INF;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(i = 2; i < 100; i++) {
        int cost = 0;
        for(j = 0; j < n; j++) {
            if (a[j] < i-1)
                cost += i-1 - a[j];
            if (a[j] > i+1)
                cost += a[j] - i-1;
        }
        if (cost < mincost)
            mincost = cost, ans = i;
    }
    cout << ans << " " << mincost;
    return 0;
}
