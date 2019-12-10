#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
vector<bool> vis1, vis2;
int32_t main() {
    IOS;
    int i, j, n, m, a;
    cin >> n >> m;
    vis1.resize(m);
    vis2.resize(m);
    for(i = 0; i < n; i++) {
        cin >> a;
        a %= m;
        for (j = 0; j < m; j++) {
            if (vis1[j]) vis2[(j+a)%m] = 1;
            if (vis2[0]) return cout << "YES", 0;
        }
        vis2[a] = 1;
        vis1 = vis2;
    }
    if (vis1[0]) cout << "YES";
    else cout << "NO";
    return 0;
}