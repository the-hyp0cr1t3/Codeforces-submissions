#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    long long n;
    cin >> n;
    cout << 24 * (1LL << (2*n-6)) + 36 * (n-3) * (1LL << (2*n-8));
    return 0;
}
