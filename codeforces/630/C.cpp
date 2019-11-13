#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    int i, n;
    long long add = 1, ans = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        add <<= 1, ans += add;
    cout << ans;
    return 0;
}
