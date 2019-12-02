#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    double i, n, m, ans = 0;
    cin >> m >> n;
    for(i = 1; i <= m; i++) 
        ans += i * (pow((i/m), n) - pow(((i-1)/m), n));
    cout << fixed << setprecision(5) << ans;
    return 0;
}