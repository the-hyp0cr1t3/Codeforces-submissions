#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ins insert
#define sz(x) (int)(x).size()
set <int> p, q, r;
int32_t main() {
    IOS;
    int i, n, x, a, cnt = 0;
    cin >> n >> x;
    for(i = 0; i < n; i++) {
        cin >> a, p.ins(a);
        r.ins(a&x);
        if ((a&x) != a)
            q.ins(a&x);
    }
    if (sz(p) < n)
        return cout << 0, 0;
    if (sz(r) == n)
        return cout << -1, 0;
    for (auto& y: q)
        if (p.count(y))
            return cout << 1, 0;
    return cout << 2, 0;
}