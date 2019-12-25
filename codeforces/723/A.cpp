#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
#define INF 2000000000 //2e9

int32_t main() {
    IOS;
    int i, n, x[3];
    for(i = 0; i < 3; i++) 
        cin >> x[i];
    sort(x, x+3);
    int ans = INF;
    for(i = x[0]; i <= x[2]; i++) 
        ans = min(ans, abs(x[0]-i)+abs(x[1]-i)+abs(x[2]-i));
    cout << ans;
    return 0;
}