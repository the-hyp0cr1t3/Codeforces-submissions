#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
int32_t main() {
    IOS;
    int Q;              
    cin >> Q;
    while (Q--) {
        int n, i, k;
        cin >> n >> k;
        if (k % 3 or k > n) {
            cout << (n%3? "Alice" : "Bob") << endl;
            continue;
        }
        n -= k;
        int x = n % (3*(k+1)), ans = 0;
        if (x == 3*k + 1 or x == 3*k + 2 or x == 0)
            ans = 1;
        else if (x > 0 and x <= k)
            ans = n%3==1? 0 : 1;
        else if (x > k and x <= 2*k)
            ans = n%3==2? 0 : 1;
        else
            ans = n%3? 1 : 0;
        cout << (ans? "Alice" : "Bob") << endl;
    }
    return 0;
}
