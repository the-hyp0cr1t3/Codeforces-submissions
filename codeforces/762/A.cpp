#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    long n, k, d;
    cin >> n >> k;
    set <long> s;
    for(d = 1; d * d <= n; d++) {
        if (n % d == 0)
            s.insert({d, n/d});
    }
    if (k <= (long) s.size())
        cout << *next(s.begin(), k-1);
    else
        cout << -1;
    return 0;
}
