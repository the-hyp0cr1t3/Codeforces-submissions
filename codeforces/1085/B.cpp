#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    int i, n, k;
    cin >> n >> k;
    int p = k;
    while(--p > 1)
        if (!(n%p)) break;
    cout << n*k/p + p;
    return 0;
}