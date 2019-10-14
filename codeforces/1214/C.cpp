#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, stack = 0, warning = 0;
    cin >> n;
    string s;
    cin >> s;
    for(i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack++;
        }
        else {
            stack--;
            if (stack < -1) {
                cout << "No";
                return 0;
            }
        }
    }
    if (stack) cout << "No";
    else cout << "Yes";
    return 0;
}