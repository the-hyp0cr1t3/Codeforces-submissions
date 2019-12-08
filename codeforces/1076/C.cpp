#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        double a, d, D;
        cin >> d;
        D = d*d - 4*d;
        cout << fixed << setprecision(10);
        if (D >= 0) {
            a = d + sqrt(D); a /= 2;
            cout << "Y " << a << " " << d-a << endl;
        }
        else
            cout << "N" << endl;
    }
    return 0;
}