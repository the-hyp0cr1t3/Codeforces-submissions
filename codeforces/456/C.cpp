#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define max(a,b) (a>b?a:b)
const int N = 1e5 + 5;
ll cache[N];
int freq[N];

ll dp (int idx) {
    if (idx <= 0)
        return 0;
    ll &ans = cache[idx];
    if (ans != -1)
        return ans;
    ans = max(dp(idx-1), dp(idx-2) + 1ll * freq[idx] * idx);
    return ans;
}

int32_t main() {
    IOS;
    memset(cache, -1, sizeof(cache));
    int i, n, a, mx = 0;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a, freq[a]++, mx = max(mx, a);
    cout << dp(mx);
    return 0;
}