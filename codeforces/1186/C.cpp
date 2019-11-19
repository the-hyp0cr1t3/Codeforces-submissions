#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define sz(x) (int)(x).size()
const int N = 1e6 + 5;
int cnt[N] = {};
int32_t main() {
    IOS;
    int i, j, n, ans = 0;
    string a, b;
    cin >> a >> b;
    int x = 0;
    for(i = 0; i < sz(b); i++)
        cnt[0] += (a[i]=='1'), x += (b[i]=='1');
    for(j = 1; i < sz(a); i++, j++)
        cnt[j] = cnt[j-1] - (a[i-sz(b)]=='1') + (a[i]=='1');
    for(i = 0; i <= sz(a)-sz(b); i++)
        if (cnt[i]&1) ans++;
    if (x%2==0)
        ans = sz(a)-sz(b)+1-ans;
    cout << ans;
    return 0;
}