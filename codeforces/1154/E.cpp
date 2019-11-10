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
#define sz(x) (int)(x).size()
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
const int N = 2e5 + 5;

int32_t main() {
    IOS;
    int i, n, k, a[N], t = 0, ans[N], pos[N], take;
    set <int> active;
    cin >> n >> k;
    for(i = 1; i <= n; i++) 
        cin >> a[i], pos[a[i]] = i, active.ins(i);
    for(i = n; i > 0; i--) {
        if (ans[pos[i]])
            continue;
        ans[pos[i]] = t+1;
        take = k;
        while (take--) {
            auto it = active.ub(pos[i]);
            if (it == active.end())
                break;
            ans[*it] = t+1;
            active.erase(it);
        }
        take = k;
        while (take--) {
            auto it = active.lb(pos[i]);
            if (it == active.begin())
                break;
            it--;
            ans[*it] = t+1;
            active.erase(it);
        }
        active.erase(active.find(pos[i]));
        t^=1;
    }
    for(i = 1; i <= n; i++) 
        cout << ans[i];
    return 0;
}
