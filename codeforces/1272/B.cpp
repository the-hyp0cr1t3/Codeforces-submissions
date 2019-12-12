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
        int n, i, j, cnt[5];
        for(i = 0; i < 5; i++) 
            cnt[i] = 0;
        string s;
        cin >> s;
        for(i = 0; i < sz(s); i++) {
            if (s[i] == 'L') cnt[0]++;
            else if (s[i] == 'U') cnt[1]++;
            else if (s[i] == 'R') cnt[2]++;
            else cnt[3]++;
        }
        cnt[0] = cnt[2] = min(cnt[0], cnt[2]);
        cnt[1] = cnt[3] = min(cnt[1], cnt[3]);
        if (cnt[0] == 0 and cnt[1] == 0) {
            cout << 0 << endl;
            continue;
        }
        if (cnt[0] == 0) {
            cout << 2 << endl;
            cout << "UD" << endl;
            continue;
        }
        if (cnt[1] == 0) {
            cout << 2 << endl;
            cout << "LR" << endl;
            continue;
        }
        cout << cnt[0]+cnt[1]+cnt[2]+cnt[3] << endl;
        for(i = 0; i < 4; i++) {
            for(j = 0; j < cnt[i]; j++) {
                char c;
                if (i == 0) c = 'L';
                else if (i == 1) c = 'U';
                else if (i == 2) c = 'R';
                else c = 'D';
                cout << c;
            }
        }
        cout << endl;
    }
    return 0;
}