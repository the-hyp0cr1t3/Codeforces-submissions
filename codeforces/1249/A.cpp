#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int q;
    cin >> q;
    while (q--){
        int n, i, a[105], flag = 1;
        cin >> n;
        for(i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        for(i = 1; i < n; i++) {
            if (a[i] == (a[i-1] + 1)) {
                flag = 2;
                break;
            }
        }
        cout << flag << endl;      
    }
    return 0;
}
