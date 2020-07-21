#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        if(s.length() <= 10)
            cout << s << endl;
        else
            cout << s.front() << s.length()-2 << s.back() << endl; 
    }
    return 0;
}