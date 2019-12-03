#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, a, cur = 1;
    long long n, ans = 0, cnt = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        cur *= abs(a)/a;
        if (cur > 0) cnt++;
    }
    ans = cnt*(cnt+1)/2 + (n-cnt)*(n-cnt-1)/2;
    cout << n*(n+1)/2 - ans << " " << ans;
    return 0;
}