#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define pb push_back
#define sz(x) (int)(x).size()
const int N = 1e6 + 5;
int dp[N];
vector<int> o;
int32_t main() {
    IOS;
    int i, n;
    ll ans = 0;
    string s;
    cin >> s;
    n = sz(s);
    dp[0] = 0;
    for(i = 1; i < n; i++) {
        dp[i] = dp[i-1] + (s[i] == 'v' and s[i-1] == 'v');
        if (s[i] == 'o') o.pb(i);
    }
    for (auto& x: o) 
        ans += 1ll * dp[x] * (dp[n-1]-dp[x]);
    cout << ans;
    return 0;
}