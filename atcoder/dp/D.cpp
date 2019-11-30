#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define INF 2000000000 //2e9
#define max(a,b) (a>b?a:b)
typedef pair<int, int> pii;
const int N = 100 + 5;
const int M = 1e5 + 2;
int val[N], wt[N];
ll cache[N][M];
//vector<pii> res;
ll dp (int idx, int rem) {
    if (rem < 0)
        return -INF;
    if (idx == 0)
        return 0;
    ll &ans = cache[idx][rem];
    if (ans != -1)
        return ans;
    ans = max(val[idx] + dp(idx-1, rem-wt[idx]), dp(idx-1, rem));
    return ans;
}

void path (int idx, int rem) {
    if (idx == 0)
        return;
    if (rem < 0)
        return;
    ll &cur = cache[idx][rem];
    if (cur == val[idx] + cache[idx-1][rem-wt[idx]]) {
//        res.push_back({wt[idx], val[idx]});
        path(idx-1, rem-wt[idx]);
    }
    else
        path(idx-1, rem);
}

int32_t main() {
    IOS;
    int i, j, n, W;
    memset(cache, -1, sizeof(cache));
    cin >> n >> W;
    for(i = 1; i <= n; i++) 
        cin >> wt[i] >> val[i];
    cout << dp(n, W) << endl;
    /*path(n, W);
    for (auto& x: res) 
        cout << "{" << x.first << ", " << x.second << "} ";*/
    return 0;
}
