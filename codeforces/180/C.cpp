#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
const int INF = 2000000000; //2e9
const int N = 2e5 + 5;
int pref[N], suf[N];

int32_t main() {
    IOS;
    int i, n, ans = INF; string s;
    cin >> s; n = s.size();

    for(i = 1; i <= n; i++) 
        pref[i] = pref[i-1] + (islower(s[i-1])? 1 : 0);
    for(i = n; i > 0; i--) 
        suf[i] = suf[i+1] + (isupper(s[i-1])? 1 : 0);

    for(i = 0; i <= n; i++) 
        ans = min(ans, pref[i] + suf[i+1]);

    cout << ans;
    return 0;
}