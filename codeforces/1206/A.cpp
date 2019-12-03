#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, n, a, p = -1, q = -1;
    cin >> n;
    while (n--)
        cin >> a, p = max(p, a);
    cin >> n;
    while (n--)
        cin >> a, q = max(q, a);
    cout << p << " " << q;
    return 0;
}