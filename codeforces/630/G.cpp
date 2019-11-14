#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    long long i, n, a = 1, b = 1;
    cin >> n;
    for(i = 0; i < 5; i++) {
        a *= (n + i), a /= (i+1);
        if (i < 3)
            b *= (n + i), b /= (i+1);
    }
    cout << a * b;
    return 0;
}