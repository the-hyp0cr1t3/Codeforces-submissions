/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2020 13:40:03
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

int ocoiek() {
    int i, n, cnt[2] = {}, ans = 0; string s;
    cin >> s; n = sz(s);

    for(i = 0; i < n; i++) {
        if(s[i] == '(')
            cnt[0]++;
        else if(s[i] == ')')
            if(cnt[0]) ans++, cnt[0]--;
        if(s[i] == '[')
            cnt[1]++;
        else if(s[i] == ']')
            if(cnt[1]) ans++, cnt[1]--;
    } cout << ans << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W