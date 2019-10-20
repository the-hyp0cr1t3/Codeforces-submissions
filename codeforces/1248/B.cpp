#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, a;
    long sum1 = 0, sum2 = 0;
    cin >> n;
    multiset <int> s;
    for(i = 0; i < n; i++) {
        cin >> a;
        s.insert(a);
    }
    i = 0;
    for (multiset <int>::iterator it = s.begin(); it != s.end(); i++, it++)
        i < n/2 ? sum1 += *it : sum2 += *it;
    cout << sum1 * sum1 + sum2 * sum2;
    return 0;
}
