#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
#define int long long

int32_t main() {
    IOS;
    int i, n, k, a, b, ans = 0;
    cin >> n >> k >> a >> b;
    while(n > 1) {
        if (n < k)
            {ans += (n%k - 1) * a; break;}
        ans += (n%k) * a;
        n -= n%k;
        if ((n - n/k)*a < b)
            {ans += (n-1)*a; break;}
        ans += b;
        n /= k;
    }
    cout << ans;
    return 0;
}