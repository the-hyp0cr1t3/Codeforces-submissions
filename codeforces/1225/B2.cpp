#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define sz(x) (int)(x).size()
#define min(a,b) (a<b?a:b)
const int N = 2e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, l, r, k, d;
        cin >> n >> k >> d;
        int ans = min(k, n);
        map <int,int> mp;
        for(i = 0; i < n; i++) 
            cin >> a[i];
        for(l = 0, r = 0; r < d; r++) 
            mp[a[r]]++;
        ans = min(ans, sz(mp));
        while(r < n) {
            if (mp[a[l]] == 1) mp.erase(a[l]);
            else mp[a[l]]--;
            mp[a[r]]++;
            ans = min(ans, sz(mp));
            l++, r++;
        }
        cout << ans << endl;
    }
    return 0;
}