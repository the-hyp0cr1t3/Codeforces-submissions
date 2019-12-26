#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int32_t main() {
    IOS;
    int i, n, a;
    cin >> n >> a;
    cout << (a & 1? (a+1)/2 : n/2+1-a/2);
    return 0;
}