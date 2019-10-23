#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int n, i, a[200010];
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = n - 1;
    long suml = a[l], sumr = a[r], sum = 0;
    while (l < r) {
        if (suml > sumr) {
            r--;
            sumr += a[r];
        }
        else if (suml < sumr) {
            l++;
            suml += a[l];
        }
        else {
            sum = max(sum, suml);
            l++;
            suml += a[l];
            r--;
            sumr += a[r];
        }
    }
    cout << sum;
    return 0;
}
