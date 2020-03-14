#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
int32_t main() {
    IOS;
    int u, v;
    cin >> u >> v;
    if(u > v or (v-u)&1) return cout << -1, 0;
    if(u == v) {
        if(u) return cout << 1 << endl << u, 0;
        else return cout << 0, 0;
    }
    int diff = (v-u)/2;
    if((u^diff)+diff == v) return cout << 2 << endl << (u^diff) << " " << diff, 0;
    cout << 3 << endl << u << " " << diff << " " << diff, 0;
    return 0;
}