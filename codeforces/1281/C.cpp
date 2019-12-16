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
        int n, i = 0;
        string s;
        cin >> n >> s;
        while(sz(s) < n) {
            i++;
            int j = s[i-1]-'1';
            string b = s.substr(i, sz(s)-i);
            while(j--) s += b;
        }
        ll ans = sz(s);
        for(i++; i <= n; i++) {
            ans = ((1ll*(s[i-1]-'0')*(ans-i))%MOD + i + MOD) % MOD;
        }
        cout << ans << endl;
    }
    return 0;
}