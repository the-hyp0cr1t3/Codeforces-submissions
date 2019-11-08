#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int main() {
    IOS;
    int i, n, a, ans = 0;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a, ans += a * i * 4;
    cout << ans;
    return 0;
}