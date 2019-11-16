#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    int t;
    cin >> t;
    while (t--) {    
        long long x, y;
        cin >> x >> y;
        if (x-y < 2)
            cout << "NO\n";
        else    
            cout << "YES\n";    
    }
    return 0;
}
