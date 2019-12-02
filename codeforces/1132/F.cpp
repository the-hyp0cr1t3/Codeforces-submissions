#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define min(a,b) (a<b?a:b)
const int N = 502;
string s;
int n, cache[N][N];
int dp (int l, int r) {
    if (l == r)
        return 1;
    if (l > r)
        return 0;
    int &ans = cache[l][r];
    if (ans != -1)
        return ans;
    ans = INF;
    ans = min(ans, 1 + dp(l+1, r));
    for(int i = l+1; i <= r; i++) 
        if (s[l] == s[i])
            ans = min(ans, dp(l+1, i-1) + dp(i, r));
    return ans;
}

int32_t main() {
    IOS;
    memset(cache, -1, sizeof(cache));
    int i;
    cin >> n >> s;
    cout << dp(0, n-1);
    return 0;
}