//https://atcoder.jp/contests/dp/tasks/dp_c
#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define max3(x,y,z) max(x,max(y,z))
#define min(a,b) (a<b?a:b)
const int N = 1e5 + 5;
int n, a[N][3], cache[N][3];

int dp (int idx, int opt) {
    if (idx < 0)
        return 0;
    int &ans = cache[idx][opt];
    if (ans != -1)
        return ans;
    ans = a[idx][opt] + max(dp(idx-1, (opt+1)%3), dp(idx-1, (opt+2)%3));
    return ans;
}

int32_t main() {
    IOS;
    int i;
    memset(cache, -1, sizeof(cache));
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i][0] >> a[i][1] >> a[i][2];
    cout << max3(dp(n, 0), dp(n, 1), dp(n, 2));
    return 0;
}