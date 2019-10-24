#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, dig;
        string s;
        cin >> s;
        deque <int> odd, even;
        
        for(i = 0; i < (int) s.length(); i++) {
            dig = s[i] - '0';
            (dig & 1) ? odd.push_back(dig) : even.push_back(dig);
        }
        
        while (odd.size() > 0 and even.size() > 0) {
            if (*odd.begin() < *even.begin()) {
                cout << *odd.begin();
                odd.pop_front();
            }
            else {
                cout << *even.begin();
                even.pop_front();
            }     
        }

        while(odd.size() > 0) {
            cout << *odd.begin();
            odd.pop_front();
        }

        while(even.size() > 0) {
            cout << *even.begin();
            even.pop_front();
        }
        cout << endl;
    }
    return 0;
}
