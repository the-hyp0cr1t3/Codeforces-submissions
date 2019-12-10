#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, n, k;
    cin >> n >> k;
    for(i = 1; i <= k; i++) {
        if (n%10 == 0) n /= 10;
        else n--;
    }
    cout << n;
    return 0;
}