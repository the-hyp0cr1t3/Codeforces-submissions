#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int q;
    cin >> q;
    while (q--){
        long n, m, i, sum = 0, sum2 = 0;
        cin >> n >> m;
        for(i = 1; i <= 10; i++)
            sum += (i*m) % 10;
        for(i = m; i <= n%(10*m); i+=m)
            sum2 += i%10;
        cout << n/(10*m) * sum + sum2 << "\n";
    }
    return 0;
}
