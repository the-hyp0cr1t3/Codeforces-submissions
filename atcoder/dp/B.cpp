//https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9
#define min(a,b) (a<b?a:b)
const int N = 2e5 + 5;
int n, k, h[N];
vector<int> cache;
int dp (int idx) {
    if (idx == 1)
        return 0;
    int &ans = cache[idx];
    if (ans != INF)
        return ans;
    for(int i = 1; i <= k; i++) 
        if (idx-i > 0)
            ans = min(ans, abs(h[idx]-h[idx-i]) + dp(idx-i));
    return ans;
}

int32_t main() {
    IOS;
    int i;
    cin >> n >> k;
    cache.assign(n+1, INF);
    for(i = 1; i <= n; i++) 
        cin >> h[i];
    cout << dp(n);
    return 0;
}
