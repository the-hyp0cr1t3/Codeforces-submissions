#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define INF 2000000000 //2e9
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
typedef pair<int, int> pii;
const int N = 1e3 + 5;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, m, a, mn1 = INF, mn1i = -1, mn2i = -1, mn2 = INF;
        cin >> n >> m;
        int ans = 0;
        for(i = 1; i <= n; i++) {
            cin >> a, ans += 2 * a;
            if (a <= mn1) {
                mn2 = mn1, mn2i = mn1i;
                mn1 = a, mn1i = i;
                continue;
            }
            if (a < mn2)
                mn2 = a, mn2i = i;
        }
        if (m < n or n == 2) {
            cout << -1 << endl;
            continue;
        }
        m -= n;
        ans += m*(mn1 + mn2);
        cout << ans << endl;
        for(i = 1; i < n; i++) 
            cout << i << " " << i+1 << endl;
        cout << n << " " << 1 << endl;
        while(m--)
            cout << mn1i << " " << mn2i << endl;
    }
    return 0;
}