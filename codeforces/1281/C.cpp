#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define sz(x) (int)(x).size()
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i = 1;
        string s;
        cin >> n >> s;
        while(sz(s) < n) {
            int j = s[i-1]-'1';
            string b = s.substr(i, sz(s)-i);
            while(j--) s += b;
            i++;
        }
        ll ans = sz(s);
        for(; i <= n; i++) {
            ans = (ans + (((1ll*(s[i-1]-'1')*(ans-i))%MOD + MOD) % MOD)) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}