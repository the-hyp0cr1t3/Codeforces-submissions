#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define MOD 1000000007  //1e9 + 7
#define sz(x) (int)(x).size()
const int N = 1e6 + 5;
ll dp[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i = 0;
        string s;
        cin >> n >> s;
        dp[0] = sz(s);
        while(sz(s) < n) {
            i++;
            int j = s[i-1]-'1';
            string b = s.substr(i, sz(s)-i);
            while(j--) s += b;
        }
        dp[i++] = sz(s);
        for(; i <= n; i++) {
            dp[i] = ((1ll*(s[i-1]-'0')*(dp[i-1]-i))%MOD + i + MOD) % MOD;
        }
        cout << dp[n] << endl;
    }
    return 0;
}