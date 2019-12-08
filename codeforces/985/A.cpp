#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min(a,b) (a<b?a:b)
const int N = 100 + 5;

int32_t main() {
    IOS;
    int i, n, p[N];
    cin >> n;
    for(i = 1; i <= n/2; i++) 
        cin >> p[i];
    sort(p+1, p+n/2+1);
    int b = 0, w = 0;
    for(i = 1; i <= n/2; i++) 
        b += abs(p[i] - i*2 + 1), w += abs(p[i] - i*2);
    cout << min(b, w);
    return 0;
}