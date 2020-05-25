#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;
const int N = 1e5 + 5;

int main() {
    int i, n, a[2 * N], k = 1;
    cin >> n;
    // if n is even, not possible
    if ((n+1) & 1) {
        cout << "NO";
        return 0;
    }
    else 
        cout << "YES" << endl;
    // a[i] is answer of i-th slot
    for(i = 1; i <= n; i+=2) {
        a[i] = k++;         // a[i] = k
        a[n+i] = k++;       // a[n+i] = k+1
        a[n+i+1] = k++;     // a[n+i+1] = k+2
        if (i < n)
            a[i+1] = k++;   // a[i+1] = k+3
    }
    for (i = 1; i <= 2 * n; i++)
        cout << a[i] << " ";
    return 0;
}