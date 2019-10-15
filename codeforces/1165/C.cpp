#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, count = 0;
    unsigned int i;
    cin >> n;
    string s;
    cin >> s;
    for(i = 0; i < s.length() - 1; i+=2) {
        if (s[i] == s[i+1]) {
            s.erase(s.begin() + i);
            count++;
            i-=2;
        }
    }
    if (n - count & 1) {
        cout << count + 1;
        s.erase(s.end() - 1);
    }
    else 
        cout << count;
    cout << "\n" << s;
    return 0;
}
