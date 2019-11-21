#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
#define all(a) a.begin(),a.end()
#define pb push_back
const int N = 1e5 + 5;
int a[N], b[N], K[N] = {};
vector<int> ans;
int32_t main() {
    IOS;
    int i, n, k, p, cnt;
    ll sum = 0;
    cin >> n >> k;
    cnt = k;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(i = 0; i < n; i++) 
        cin >> b[i];
    for(i = 0; i < n; i++) {
        if (!K[a[i]])
            K[a[i]] = b[i], cnt--;
        else if (b[i] > K[a[i]])
            ans.pb(K[a[i]]), K[a[i]] = b[i];
        else
            ans.pb(b[i]);
    }
    sort(all(ans));
    for (i = 0; i<cnt;i++)
        sum += ans[i];
    cout << sum;
    return 0;
}