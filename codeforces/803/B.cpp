#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)

int32_t main() {
    IOS;
    int i, j, a, n;
    cin >> n;
    vector<int> z;
    for(i = 1; i <= n; i++) {
        cin >> a;
        if (!a) z.push_back(i);
    }
    for(i = 1, j = 0; i <= n; i++) {
        if (i <= z[0])
            cout << z[0] - i << " ";
        else if (i > z.back())
            cout << i - z.back() << " ";
        else {
            int x = min(abs(z[j]-i), abs(z[j+1]-i));
            if (!x) j++;
            cout << x << " ";
        }
    }
    return 0;
}