#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, a, b;
    cin >> a >> b;
    if (a == 9 and b == 1)
        cout << "9 10";
    else if (a > b or b-a > 1)
        cout << -1;
    else if (a == b)
        cout << a << 0 << " " << b << 1;
    else
        cout << a << 9 << " " << b << 0;
    return 0;
}