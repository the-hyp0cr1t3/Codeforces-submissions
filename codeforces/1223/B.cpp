#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define ins insert

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i;
        string s, t;
        cin >> s >> t;
        bool ans = 0;
        set <char> st;
        for (auto c: s) 
            st.ins(c);
        for (auto c: t) 
            if (st.count(c)) ans = 1;
        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}