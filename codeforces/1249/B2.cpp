#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 2e5 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, ans[N] = {}, a[N], pos;
        cin >> n;
        for(i = 1; i <= n; i++)
            cin >> a[i];
        for(i = 1; i <= n; i++) {
            vector<int> v;
            int count = 0;
            pos = i;
            if(ans[i])
                continue;
            else {
                do {
                    pos = a[pos];
                    v.pb(pos);
                    count++;
                } while (pos != i);
                for (auto& x: v)
                    ans[x] = count;
            }
        }
        for(i = 1; i <= n; i++) 
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
