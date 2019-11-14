#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    long long n, ans;
    cin >> n;
    ans = n;
    ans -= n/2 + n/3 + n/5 + n/7 + n/30 + n/105 + n/70 + n/42;
    ans += n/6 + n/15 + n/35 + n/10 + n/14 + n/21 + n/210;
    cout << ans;
    return 0;
}