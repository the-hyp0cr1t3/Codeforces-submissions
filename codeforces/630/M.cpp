#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    long long n, ans;
    cin >> n;
    ans = abs(n) % 360;
    if (n < 0) ans = 360 - ans;
    if (ans <= 45 or ans >= 315)
        return cout << 0, 0;
    if (ans <= 135)
        return cout << 1, 0;
    if (ans <= 225)
        return cout << 2, 0;
    return cout << 3, 0;
}