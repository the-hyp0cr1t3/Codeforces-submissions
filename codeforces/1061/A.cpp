#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int i, n, S, ans = 0;
    cin >> n >> S;
    while (S) {
        ans += S/n;
        S %= n;
        n--;
    }
    cout << ans;
    return 0;
}