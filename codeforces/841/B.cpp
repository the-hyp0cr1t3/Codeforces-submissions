#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
int32_t main() {
    IOS;
    int a, n;
    cin >> n;
    while (n--) {
        cin >> a;
        if (a&1) return cout << "First", 0;
    }
    return cout << "Second", 0;
}