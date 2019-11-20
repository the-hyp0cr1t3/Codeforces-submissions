#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define min(a,b) (a<b?a:b)
string text = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    while (Q--) {
        int r, c, k, i, j, rice = 0, sum = 0, p = 1, D = 0;
        cin >> r >> c >> k;
        vector<string> s(r);
        for(i = 0; i < r; i++) 
            cin >> s[i], rice += (int)count(all(s[i]),'R');
        for(i = 0; i < r; i++) {
            if (i & 1) reverse(all(s[i]));
            for(j = 0; j < c; j++) {
                sum += (s[i][j]=='R');
                s[i][j] = text[D];
                if (sum == rice/k * p + min(p, rice%k)) p++, D = min(D+1, k-1);
            }
            if (i & 1) reverse(all(s[i]));
        }
        for(i = 0; i < r; i++) 
            cout << s[i] << endl;
    }
    return 0;
}