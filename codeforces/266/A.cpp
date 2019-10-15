#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, count = 0;
    string s;
    cin >> n;
    cin >> s;
    for(i = 1; i < n; i++) {
        if (s[i]==s[i-1])
            count++;
    }
    cout << count;
    return 0;
}
