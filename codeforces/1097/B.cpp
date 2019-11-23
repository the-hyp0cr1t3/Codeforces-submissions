#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int N = 15 + 5;

int32_t main() {
    IOS;
    int i, n, a[N], sum = 0, res;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i], sum += a[i], sum %= 360;
    for(i = 0; i < pow(2, n); i++) {
        bitset<15> b(i);
        res = sum;
        for(int j = 0; j < n; j++) 
            if (!b[j])
                res -= 2*a[j], res += 360, res %= 360;
        if (!res)
            return cout << "YES", 0;
    }
    return cout << "NO", 0;
}