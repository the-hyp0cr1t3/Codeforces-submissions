#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define mp make_pair
typedef pair<int, int> pii;
const int N = 2e5 + 5;
map <pii,int> d;
int a[N], b[N];
int32_t main() {
    IOS;
    int i, n, ans = 0, k = 0;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(i = 0; i < n; i++) 
        cin >> b[i];
    for(i = 0; i < n; i++) {
        if (!a[i]) {
            ans += !b[i];
            continue;
        }
        int x = __gcd(a[i], b[i]);
        d[mp(-b[i]/x, a[i]/x)]++;
    }
    for (auto& x: d) 
        k = max(k, x.second);
    ans += k;
    cout << ans;
    return 0;
}