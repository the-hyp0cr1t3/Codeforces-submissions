/**
 🍪 the_hyp0cr1t3
 🍪 02.12.2020 00:18:44
**/
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

int main() {
    int i, j; array<int64_t, 3> a;
    cin >> a[0] >> a[1] >> a[2];
    
    cout << "First" << endl;
    
    cout << (*max_element(all(a)) - *min_element(all(a))) << endl;
    cin >> i;
    a[--i] += *max_element(all(a)) - *min_element(all(a));

    cout << (a[i]*3 - accumulate(all(a), 0ll)) << endl;
    cin >> j;
    a[--j] += a[i]*3 - accumulate(all(a), 0ll);

    cout << a[j] - a[i] << endl;
    cin >> i;
} // ~W 