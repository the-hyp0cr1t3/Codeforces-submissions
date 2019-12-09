#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 1e5 + 5;

int32_t main() {
    IOS;
    int i, a, b, c, d;
    cin >> a >> b >> c >> d;
    while (b != d and b < N) b>d? d+=c : b+=a;
    cout << (b==d?b:-1);
    return 0;
}