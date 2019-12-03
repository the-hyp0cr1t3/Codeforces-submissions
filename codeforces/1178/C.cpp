#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define MOD 998244353
template <typename T, typename T1>
T expo (T a, T1 b) {
    if (b == 0)
        return 1;
    if (b & 1)
        return (int)(1ll * a * expo(a, b-1) % MOD);
    a = expo(a, b/2);
    return (int)(1ll * a * a % MOD);
}
int32_t main() {
    IOS;
    int i, w, h;
    cin >> w >> h;
    cout << expo(2, w+h);
    return 0;
}