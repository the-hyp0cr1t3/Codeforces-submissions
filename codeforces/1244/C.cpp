#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;

int32_t main() {
    IOS;
    int i, n, p, w, d;
    cin >> n >> p >> w >> d;
    for(i = 0; i < w; i++) {
        int x = p-d*i;
        if (x >=0 and x%w==0 and x/w + i <= n)
            return (cout << x/w << " " << i << " " << n-i-x/w), 0;
    }
    return cout << -1, 0;
}