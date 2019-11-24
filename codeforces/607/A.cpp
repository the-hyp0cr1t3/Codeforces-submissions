#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define INF 2000000000 //2e9
#define lb lower_bound
#define pb push_back
#define all(a) a.begin(),a.end()
#define min(a,b) (a<b?a:b)
#define f first
#define s second
const int N = 1e5 + 5;
typedef pair<int, int> pii;
int aoe[N], cache[N];
int dp (int idx) {
    if (idx < 0)
        return 0;
    int &ans = cache[idx];
    if (ans != -1)
        return ans;
    ans = aoe[idx] + dp(idx - aoe[idx] - 1);
    return ans;
}
int32_t main() {
    IOS;
    int i, n, ans = INF;
    cin >> n;
    memset(cache, -1, sizeof(cache));
    vector<pii> a(n);
    for(i = 0; i < n; i++) 
        cin >> a[i].f >> a[i].s;
    sort(all(a));
    vector<int> p, q;
    for(i = 0; i < n; i++) 
        p.pb(a[i].f), q.pb(a[i].s);
    for(i = 0; i < n; i++) {
        auto cnt = lb(all(p), p[i]) - lb(all(p), p[i]-q[i]);
        aoe[i] = (int)cnt;
    }
    for(i = n-1; i >= 0; i--)
        ans = min(ans, n-i-1 + dp(i));
    cout << ans;
    return 0;
}