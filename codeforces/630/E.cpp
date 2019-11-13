#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    long long x1, x2, y1, y2, y, x;
    cin >> x1 >> y1 >> x2 >> y2;
    y = (y2-y1)/2;
    x = x2 - x1;
    cout << (y+1)*(x+1) - (x/2);
    return 0;
}