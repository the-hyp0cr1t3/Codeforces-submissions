#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
int32_t main() {
    IOS;
    int i, n;
    ll ans = 0;
    cin >> n;
    for(i = 2; i < n; i++) 
        ans += i*(i+1);
    cout << ans;
    return 0;
}