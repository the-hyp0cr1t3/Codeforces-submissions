#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i,sum = 0;
    string s;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> s;
        sum += s[1] == '+' ? 1 : -1;
    }
    cout << sum;    
    return 0;
}
