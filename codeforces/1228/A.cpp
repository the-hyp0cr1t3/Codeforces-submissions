#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define ins insert
#define sz(x) (int)(x).size()

bool work (int x) {
    set <int> s;
    while(x) {
        if (s.count(x%10)) return 0;
        s.ins(x%10);
        x /= 10;
    }
    return 1;
}

int32_t main() {
    IOS;
    int l, r, i;
    cin >> l >> r;
    for(i = l; i <= r; i++) 
        if (work(i)) return cout << i, 0;
    cout << -1;
    return 0;
}