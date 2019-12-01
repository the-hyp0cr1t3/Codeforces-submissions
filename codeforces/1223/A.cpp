#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i;
        cin >> n;
        if (n == 2)
            cout << 2 << endl;
        else
            cout << (n & 1) << endl;
    }
    return 0;
}