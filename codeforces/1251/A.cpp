#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int q;
    cin >> q;
    while (q--) {
        int i, count = 0;
        char letter = ' ';
        set <char> res;
        
        string s;
        cin >> s;
        for(i = 0; i < (int) s.size(); i++) {
            if (s[i] == letter)
                count++;
            else {
                if (count & 1)
                    res.insert(letter);
                count = 1;
                letter = s[i];
            }
        }
        if (count & 1)
            res.insert(letter);
        for (auto& x: res) {
            cout << x;
        }
        cout << endl;
    }
    return 0;
}
