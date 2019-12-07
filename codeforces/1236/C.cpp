#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define pb push_back

int32_t main() {
    IOS;
    int i, j, k, n;
    cin >> n;
    vector<vector<int>> v(n+2);
    for(i = 1, j = 0, k = 1; k <= n*n; k++) {
        if (i == n+1 or i == 0) j^=1, j? i--: i++;
        v[i].pb(k);
        j? i--: i++;
    }
    for (auto& x: v) {
        for (auto& y: x) 
            cout << y << " ";
        cout << endl;
    }
    return 0;
}