#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
const int N = 7e3 + 5;
ll a[N], b[N];
map <ll,ll> cnt, lone;
int32_t main() {
    IOS;
    int i, n;
    ll ans = 0;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i], cnt[a[i]]++;
    for(i = 0; i < n; i++) 
        cin >> b[i];

    for(i = 0; i < n; i++) {
        if (cnt[a[i]] > 1) ans += b[i];
        else lone[a[i]] = b[i], cnt.erase(a[i]);
    }

    for (auto& [k, v]: lone) {
        for (auto& [p, q]: cnt) {
            if ((k | p) == p) {
                ans += v;
                break;
            }
        }
    }
    cout << ans;
    return 0;
}