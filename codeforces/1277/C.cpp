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
        int n, i, cnt = 0;
        string s, t;
        cin >> s;
        vector<int> ans;
        for(i = 0; i < sz(s)-2;) {
            if (i < sz(s)-4 and s.substr(i, 5) == "twone")
                {cnt++; ans.pb(i+2); i += 5; continue;}
            t = s.substr(i, 3);
            if (t == "one" or t == "two")
                cnt++, ans.pb(i+1), i += 3;
            else
                i++;
        }
        cout << cnt << endl;
        for (auto& x: ans) 
            cout << x+1 << " ";
        cout << endl;
    }
    return 0;
}
/*
onet onet ooneooonetwooo
onetwonetwooneooonetwooo
*/