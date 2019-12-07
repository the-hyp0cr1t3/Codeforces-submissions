#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, n, a, ans = 0;
    cin >> n;
    vector<bool> vis(n+1);
    queue <int> q;
    for(i = 0; i < n; i++) 
        cin >> a, q.push(a);
    for(i = 0; i < n; i++) {
        cin >> a;
        while (vis[q.front()] and !q.empty()) 
            q.pop();
        if (q.front() != a) ans++;
        else q.pop();
        vis[a] = 1;
    }
    cout << ans;
    return 0;
}