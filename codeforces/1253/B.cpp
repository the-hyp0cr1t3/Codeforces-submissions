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

int32_t main() {
    IOS;
    int i, n, a, size = 0, d = 0, prv = -1;
    bool flag = 0;
    cin >> n;
    vector<int> ans;
    map <int,int> events;
    for(i = 0; i < n; i++) {
        cin >> a;
        if (a > 0) {
            if (events[a] != 0) {
                flag = 1;
                break;
            }
            events[a] = 1, size++;
        }
        else {
            if (events[-a] != 1) {
                flag = 1;
                break;
            }
            events[-a] = -1, size--;
            if (!size) {
                events.clear();
                d++;
                ans.pb(i-prv);
                prv = i;
            }
        }
    }
    if (size > 0) flag = 1;
    if (flag)
        return cout << -1, 0;
    cout << d << endl;
    for (auto& x: ans) 
        cout << x << " ";
    return 0;
}
