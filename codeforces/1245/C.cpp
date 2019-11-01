#include <bits/stdc++.h>
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
ll dp[N];
ll Dp (ll x){
    if (dp[x] != -1)
        return dp[x] % MOD;
    else {
        dp[x] = Dp(x-1) + Dp(x-2);
        return dp[x] % MOD;
    }
}

int main() {
    ll i, n, countn = 0, countu = 0, ans = 1;
    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(i = 0; i < (int)s.length(); i++) {
        if (s[i]=='m' or s[i]=='w') {
            cout << 0;
            return 0;
        }
        if (s[i]=='n')
            countn++;
        else {
            if(countn)
                ans *= Dp(countn), ans %= MOD;
            countn = 0;
        }
        if (s[i]=='u')
            countu++;
        else {
            if(countu)
                ans *= Dp(countu), ans %= MOD;
            countu = 0;
        }
    }
    if(countu)
        ans *= Dp(countu), ans %= MOD;
    if(countn)
        ans *= Dp(countn), ans %= MOD;
    cout << ans;
    return 0;
}
