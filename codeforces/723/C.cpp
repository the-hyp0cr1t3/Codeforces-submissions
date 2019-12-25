#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
typedef pair<int, int> pii;
const int N = 2e3 + 5;
int freq[N], a[N];
int32_t main() {
    IOS;
    vector<int> js;
    int i, n, m, k, ans = 0, cur = 1;
    cin >> n >> m;
    k = n/m;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] <= m) 
            freq[a[i]]++;
    }
    for(i = 0; i < n; i++) {
        if (a[i] <= m and freq[a[i]] <= k) continue;
        while (cur <= m and freq[cur] >= k) cur++;
        if (cur > m) break;
        if (a[i] <= m) freq[a[i]]--;
        freq[cur]++;
        a[i] = cur;
        ans++;
    }
    cout << k << " " << ans << endl;
    for(i = 0; i < n; i++) 
        cout << a[i] << " ";
    return 0;
}