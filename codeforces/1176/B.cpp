#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, a, cnt[3], ans = 0;
        cin >> n;
        memset(cnt, 0, sizeof(cnt));
        for(i = 0; i < n; i++) {
            cin >> a;
            a % 3 ? a % 3 == 1 ? cnt[1]++ : cnt[2]++ : cnt[0]++;
        }
        ans = cnt[0];
        n = min(cnt[1], cnt[2]);
        ans += n;
        cnt[1] -= n;
        cnt[2] -= n;
        ans += cnt[1]/3;
        ans += cnt[2]/3;
        cout << ans << endl;
    }
    return 0;
}