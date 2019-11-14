#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    long long i, n, ans = 1;
    cin >> n;
    for(i = 0; i < 5; i++) 
        ans *= (n-i), ans /= (i+1);
    ans *= ans * 120;
    cout << ans;
    return 0;
}