#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define DESPACITO 1000000000000000000 //1e18
#define PI acos(-1);
#define E 998244353
#define mp make_pair
#define lb lower_bound
#define ub upper_bound
#define all(a) a.begin(),a.end()
#define Y second
#define X first
#define ins insert
#define pb push_back
#define sz(x) (int)(x).size()
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int, int> pii;
const int N = 1e5 + 5;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, p, prv = -1, cnt = 0, j = 1, g, b, s;
        cin >> n;
        vector<int> pref(n+2);
        for(i = 1; i <= n; i++) {
            cin >> p;
            if (prv == -1) prv = p;
            if (p != prv)
                pref[j] = pref[j-1] + cnt, cnt = 1, j++, prv = p;
            else
                cnt++;
        }
        pref[j] = pref[j-1] + cnt;
        int mx = pref[j]/2;
        //handle all equal case
        for(i = 1; i <= j-1; i++) 
            if (pref[i] <= mx and pref[i+1] > mx) break;
        int mid = i;
        //handle not enough groups
        g = pref[1];
        for(i = 2; i < mid-1; i++) 
            if (g < pref[mid] - pref[i] and g < pref[i] - g) break;
        s = pref[i] - g;
        b = pref[mid] - pref[i];
        if (mid < 3 or i == mid or g >= b or g >= s)
            g = s = b = 0;
        cout << g << " " << s << " " << b << endl;
    }
    return 0;
}