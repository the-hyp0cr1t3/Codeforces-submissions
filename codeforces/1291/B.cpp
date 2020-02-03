#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 3e5 + 5;
int a[N];
bool pref[N], suf[N];

int solve () {
    int i, n;
    cin >> n; 
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    pref[0] = suf[n+1] = 1;

    for(i = 1; i <= n; i++) {
        bool x = (a[i] >= i-1);
        pref[i] = (x & pref[i-1]);
    }
    for(i = n; i; i--) {
        bool x = (a[i] >= n-i);
        suf[i] = (x & suf[i+1]);
    }

    for(i = 1; i <= n; i++) {
        if (pref[i-1] and suf[i+1] and a[i] >= max(i-1, n-i)) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}

int32_t main() {
    IOS;
    int Q;
    for(cin >> Q; Q; Q--)
        solve();
    return 0;
}