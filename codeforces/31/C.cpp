#include <bits/stdc++.h>
#define cerr if(1)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define max3(x,y,z) max(x,max(y,z))
#define min3(x,y,z) min(x,min(y,z))
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
const int N = 5000 + 5;

int main() {
    IOS;
    int i, n, l[N], r[N], cnt = 0;
    bool flag;
    cin >> n;
    map <int,int> events;
    vector<int> ans;
    for(i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        events[l[i]]++;
        events[r[i]]--;
    }
    
    for(i = 0; i < n; i++) {
        flag = 0;
        events[l[i]]--, events[r[i]]++;
        cnt = 0;
        for (auto& [k, v]: events) {
            cnt += v;
            if (cnt > 1)
                flag = 1;
        }
        if (!flag)
            ans.pb(i);
        events[l[i]]++, events[r[i]]--;
    }

    cout << ans.size() << endl;
    for (auto& x: ans) 
        cout << x+1 << " "; 
    return 0;
}
