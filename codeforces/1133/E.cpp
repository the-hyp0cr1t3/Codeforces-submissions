#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define max(a,b) (a>b?a:b)
#define INF 2000000000 //2e9
const int N = 5e3 + 5;
int a[N], k, n, cache[N][N], nxt[N];

int dp (int idx, int teams) {
    if (idx == n or teams == k)
        return 0;
    if (teams > k)
        return -INF;
    int &ans = cache[idx][teams];
    if (ans != -1)
        return ans;
    return ans = max(dp(idx+1, teams), nxt[idx]-idx+dp(nxt[idx], teams+1));
}

int32_t main() {
    IOS;
    memset(cache, -1, sizeof(cache));
    int i, j, teams = 1, l = 0, r = 0;
    cin >> n >> k;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+n);
    while (l < n) {
        while (r < n and a[r]-a[l] <= 5) r++;
        nxt[l++] = r;
    }
    cout << dp(0, 0);
    return 0;
}