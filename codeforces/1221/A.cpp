#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, i, j, x, f[30] = {}, done = 0, red = 0, add;
        cin >> n;
        for(i = 0; i < n; i++) {
            cin >> x;
            f[(int)log2(x)]++;
        }
        if (f[11]) {
            cout << "YES\n";
            continue;
        }
        for(i = 10; i >= 0; i--) {
//            add = j == -1? 0 : (int)pow(2, j);
            if (f[i] >= (int)pow(2, 11 - i) - red) {
                cout << "YES\n";
                done = 1;
                break;
            }
            else {
                red += f[i];
                red *= 2;
            }
        }
        if (!done)
            cout << "NO\n";

    }    
    return 0;
}
