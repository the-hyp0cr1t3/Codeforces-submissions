#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, x1, x2, x3, y1, y2, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    int64_t cross = 1ll*(x2-x1)*(y3-y2) - 1ll*(y2-y1)*(x3-x2);
    string s;
    if (!cross) 
        s = "TOWARDS";
    else if (cross > 0) 
        s = "LEFT";
    else
        s = "RIGHT";
    cout << s;
    return 0;
}