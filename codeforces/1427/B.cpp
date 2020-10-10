/**
 🍪 the_hyp0cr1t3
 🍪 10.10.2020 20:26:30
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int the_real_main() {
    int i, j, n, k, ans = 0; string s;
    cin >> n >> k >> s;
    
    if(s == string(n, 'L')) {
        ans = max(0, k * 2 - 1);
        return cout << ans << '\n', 0;
    }
    

    s = '#' + s + '#';
    for(i = 1; i <= n; i++)
        if(s[i] == 'W') ans += 1 + (s[i-1] == 'W');

    int fst = 1, lst = n;
    while(fst <= n and s[fst] == 'L') fst++;
    while(lst and s[lst] == 'L') lst--;

    vector<int> diffs;
    for(i = j = fst; i <= lst;) {
        j = i+1;
        while(j <= lst and s[j] == 'L') j++;
        if(j-i-1) diffs.pb(j-i-1);
        i = j;
    } sort(all(diffs));

    for(i = 0; i < sz(diffs); i++) {
        if(!k) break;
        if(k >= diffs[i]) ans += 2*diffs[i] + 1, k -= diffs[i];
        else ans += 2*k, k = 0;
    }

    if(k) {
        int take = min(n-lst, k);
        ans += take * 2;
        k -= take;
        if(k) {
            take = min(k, fst-1);
            ans += take * 2;     
        }
    }
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}