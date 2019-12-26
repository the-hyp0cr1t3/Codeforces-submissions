#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define MOD 1000000007  //1e9 + 7
const int N = 1005;
int dp[N], ncr[N][N];
int32_t main() {
    IOS;
    int i, j, k;
    ll ans = 0;
    string s;
    dp[1] = 0;
    for(i = 2; i < N; i++)
        dp[i] = 1 + dp[__builtin_popcount(i)];
    for(i = 0; i < N; i++) {
        ncr[i][0] = ncr[i][i] = 1;
        for(j = 1; j < i; j++) 
            ncr[i][j] = (int)((1ll*ncr[i-1][j] + ncr[i-1][j-1]) % MOD);
    }
    cin >> s >> k;
    if (!k) return cout << 1, 0;
    if (k == 1) ans--;
    for(i = 1; i <= sz(s); i++) {
        if (dp[i] == k-1) {
            int cnt = 0;
            ans += (count(all(s), '1') == i); ans %= MOD;
            for(j = 0; j < sz(s) and i >= cnt; j++) {
                if (s[j] == '1') {
                    ans += ncr[sz(s)-j-1][i-cnt]; ans %= MOD;
                    cnt++;
                }
            }
        }
    }
    cout << ans;
    return 0;
}