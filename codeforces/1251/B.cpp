#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, a, b, count = 0, stack = 0;
        bool flag = 0, taken = 0;
        cin >> n;
        string s[51];
        for(i = 0; i < n; i++) {
            cin >> s[i];
            a = b = 0;
            for(int j = 0; j < (int) s[i].size(); j++) {
                if (s[i][j] == '1')
                    a++;
                else
                    b++;
            }
            if (a & 1 and b & 1) {
                if (!taken) 
                    stack++, taken = 1;
                else
                    stack--, count += 2, taken = 0;
            }
            else if (!(a & 1) and !(b & 1))
                count++;
            else
                count ++, flag = 1;
        }
        if (stack != 0 and flag)
            count++;
        cout << count << endl;
    }
    return 0;
}
        