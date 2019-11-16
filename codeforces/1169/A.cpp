#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, n, a, x, b, y;
    cin >> n >> a >> x >> b >> y;
    while (a^x and b^y) {
        if (a == b)
            return cout << "YES", 0;
        if (++a > n)
            a = 1;
        if (!--b)
            b = n;
    }
    if (a == b)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
