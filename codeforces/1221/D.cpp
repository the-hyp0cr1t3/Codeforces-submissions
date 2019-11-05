#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define DESPACITO 1000000000000000000
#define int long long

using namespace std;
const int N = 3e5 + 10;
int a[N], b[N], n;
int cache[N][3];

int dp (int idx, int prv) {
    if (idx == 0)
        return 0;
    int &ans = cache[idx][prv];
    if (ans != -1)
        return ans;
    ans = DESPACITO;
    for(int i = 0; i < 3; i++) {
        if (a[idx] + i == a[idx+1] + prv)
            continue;
        ans = min(ans, dp(idx-1, i) + b[idx] * i);
    }
    return ans;
}

int32_t main() {
    IOS;
    int q;
    cin >> q;
    while (q--) {
        int i;
        cin >> n;
        for(i = 1; i <= n; i++) {
            cin >> a[i] >> b[i];
            for(int j = 0; j < 3; j++) 
                cache[i][j] = -1;
        }
        a[n+1] = b[n+1] = 0;
        cout << dp(n, 0) << endl;
    }
    return 0;
}   
