#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n % 3 == 2) n++;
        for(i = n; ;) {
            n = i;
            while (n && (n % 3 != 2))
                n /= 3;
            if (!n) {
                cout << i << endl;
                break;
            }
            (i % 3) == 1? i+=2 : i++;
        }
    }
    return 0;
}
