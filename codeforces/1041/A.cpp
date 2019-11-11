#include <bits/stdc++.h>
using namespace std;
#define long int64_t
const int N = 1e9 + 3;


int main() {
    int n, mina = INT_MAX, maxa = 0, i, a, count = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        mina = min(mina, a);
        maxa = max(maxa, a);
    }
    
    cout << maxa - mina + 1 - n;
    
    return 0;
}
