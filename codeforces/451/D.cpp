#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
#define sz(Xx) (int)(Xx).size()

int32_t main() {
    IOS;
    int i, n, odd = 0, even = 0; string s;
    cin >> s; n = sz(s);
    vector<int> oddpos(2), evenpos(2);
    for(i = 0; i < n; i++) {
        if(i&1) {
            oddpos[s[i]-'a']++;
            odd += oddpos[s[i]-'a'];
            even += evenpos[s[i]-'a'];
        }
        else {
            evenpos[s[i]-'a']++;
            odd += evenpos[s[i]-'a'];
            even += oddpos[s[i]-'a'];            
        }
    }
    cout << even << " " << odd;
    return 0;
}