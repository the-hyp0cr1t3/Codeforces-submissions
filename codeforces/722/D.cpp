#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ins insert

int32_t main() {
    IOS;
    int i, n, a;
    cin >> n;
    set <int, greater<int>> s;
    for(i = 0; i < n; i++) 
        cin >> a, s.ins(a);
    while(1) {
        int x = *s.begin();
        while(x and s.count(x)) x /= 2;
        if (!x) break;
        s.erase(s.begin());
        s.ins(x);
    }
    for (auto& x: s) 
        cout << x << " ";
    return 0;
}