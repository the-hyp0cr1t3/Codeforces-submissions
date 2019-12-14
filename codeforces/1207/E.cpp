#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int query (int opt) {
    int t = 100;
    cout << "? ";
    int m = 1;
    while (t--) {
        cout << (m<<(7*opt));
        if (t) cout << " ";
        m++;
    }
    cout << endl;
    cin >> m;
    return m;
}

int32_t main() {
    IOS;
    int n;
    bitset<15> ans(0);
    n = query(0);
    bitset<15> b1(n);
    for(int i = 7; i < 14; i++) 
        if(b1[i]) ans.set(i, 1);
    n = query(1);
    bitset<15> b2(n);
    for(int i = 0; i < 7; i++) 
        if(b2[i]) ans.set(i, 1);
    cout << "! " << ans.to_ulong() << endl;
    return 0;
}