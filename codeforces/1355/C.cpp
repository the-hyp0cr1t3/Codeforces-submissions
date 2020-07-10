#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
const int N = 1e6 + 5;
ll pref[N];
int32_t main() {
    IOS;
    int i, a, b, c, d; ll ans = 0;
    cin >> a >> b >> c >> d;
    for(i = a; i <= b; i++) {
        pref[i+b-1]++;
        pref[i+c]--;
    }
    for(i = 1; i < N; i++) 
        pref[i] += pref[i-1];
    for(i = c; i < N; i++)
        ans += pref[i] * (min(i, d)-c+1);
    cout << ans;
    return 0;
}