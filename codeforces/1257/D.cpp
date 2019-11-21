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
const int N = 2e5 + 5;
int mon[N];
vector<int> pref;

bool check (int x, int pos) {
    int i, mx = 0;
    for(i = pos; i <= x; i++) 
        if (pref[x-pos+1] < mon[i])
            return 0;
    return 1;
}

int binarySearch(int low, int high, int pos) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid, pos))
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low; 
}

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, j, p, s, m, cur = 1, ans = 0;
        bool flag = 0;
        cin >> n;
        pref.assign(n+2, 0);
        for(i = 1; i <= n; i++) 
            cin >> mon[i];
        cin >> m;
        for(i = 1; i <= m; i++)
            cin >> p >> s, pref[s] = max(pref[s], p);

        for(i = n; i > 0; i--)
            pref[i] = max(pref[i+1], pref[i]);
        
        while (cur <= n) {
            int move = binarySearch(cur, n, cur);
            ans++;
            if (move <= cur) {
                flag = 1;
                break;
            }
            cur = move;
        }
        if (flag)
            cout << -1 << endl;
        else
            cout << ans << endl;
    }
    return 0;
}