#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 2e5 + 10;
int a[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, j, ans = 0, bal= 0;
        cin >> n;
        map <int,int> left;
        left[0] = 0;
        for(i = 1; i <= 2*n; i++) {
            cin >> a[i];
            a[i] = a[i] == 1? 1 : -1;
            if (i > n) continue;
            bal += a[i];
            left[bal] = i;
        }
        ans = max(ans, left[0]);
        bal = 0;
        for(i = 2*n; i > n; i--) {
            bal += a[i];
            if (left.count(-bal))
                ans = max(ans, 2*n - i + 1 + left[-bal]);
        }
        cout << 2*n - ans << endl;
    }
    return 0;
}