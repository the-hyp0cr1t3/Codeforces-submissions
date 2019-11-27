#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int r, b, k;
        cin >> r >> b >> k;
        if (r > b) swap(r, b);
        if ((b-1+r-__gcd(r,b))/r < k)
            cout << "OBEY" << endl;
        else
            cout << "REBEL" << endl;
    }
    return 0;
}