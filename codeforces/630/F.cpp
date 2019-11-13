#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    long long a = 1, b, c, i, n;
    cin >> n;
    for(i = 0; i < 5; i++) 
        a *= (n - i), a /= (i+1);
    b = a * (n - 5) / 6;
    c = b * (n - 6) / 7;
    cout << a + b + c;
    return 0;
}