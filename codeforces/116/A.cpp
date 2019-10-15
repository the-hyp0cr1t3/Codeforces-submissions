#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, a, b, count = 0, max = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a >> b;
        count -= a;
        count += b;
        if(max < count) max = count;
    }
    cout << max;
    return 0;
}
