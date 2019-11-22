#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;

int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int n, i, cnt1[27] = {}, cnt2[27] = {}, par1 = 0, par2 = 0;
        int flag = 1;
        string s, t;
        cin >> n >> s >> t;
        for(i = 0; i < n; i++) 
            cnt1[s[i]-'a']++, cnt2[t[i]-'a']++;
        for(i = 0; i < 26; i++) {
            if (cnt1[i] != cnt2[i]) {
                flag = 0;
                break;
            }
            if (cnt1[i]>1)
                flag = 2;
        }
        if (!flag) {
            cout << "NO" << endl;
            continue;
        }
        if (flag == 2) {
            cout << "YES" << endl;
            continue;
        }
        for(i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if (s[i] > s[j]) par1++;
                if (t[i] > t[j]) par2++;
            }
        }
        if ((par1&1) == (par2&1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}