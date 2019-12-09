#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 2e5 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, n, k;
    cin >> n >> k;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+n);
    if (!k) {
        if (a[0] == 1) cout << -1;
        else cout << 1;
    }
    else if (a[k-1] != a[k]) cout << a[k-1];
    else cout << -1;
    return 0;
}