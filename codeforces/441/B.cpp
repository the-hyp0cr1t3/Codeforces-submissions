#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 3000 + 5;
int day[N], remaining[N];

int32_t main() {
    IOS;
    int i, n, v, ans = 0;
    cin >> n >> v;
    for(i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        day[a] += b;
    }
    for(i = 0; i < N-1; i++) {
        int take = min(v, remaining[i]);
        int left = v - take;
        ans += take;
        take = min(left, day[i]);
        ans += take;
        remaining[i+1] += day[i] - take;
    }
    cout << ans;
    return 0;
}