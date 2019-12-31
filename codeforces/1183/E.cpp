#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
#define min(a,b) (a<b?a:b)
const int N = 100 + 5;
const int M = 26;
string s;
int n, k;
int last[N][M], dp[N][N];
int32_t main() {
    IOS;
    int i, j, ans = 0;
    cin >> n >> k >> s;
    k--;
    for(i = 0; i < n; i++) {
        for(j = 0; j < M; j++) 
            last[i][j] = i? last[i-1][j] : -1;
        last[i][s[i]-'a'] = i;
    }

    for(i = 0; i < n; i++) 
        dp[i][1] = 1;

    for(int len = 2; len < n; len++)
        for(i = 1; i < n; i++)
            for(j = 0; j < M; j++) 
                if (last[i-1][j] != -1) dp[i][len] += dp[last[i-1][j]][len-1];

    for(int len = n-1; len; len--) {
        int cnt = 0;
        for(j = 0; j < M; j++) 
            if (last[n-1][j] != -1) cnt += dp[last[n-1][j]][len];
        ans += min(k, cnt) * (n-len);
        k -= min(k, cnt);
        if (!k) break;
    }
    if (k) k--, ans += n;
    cout << (k? -1 : ans);
    return 0;
}