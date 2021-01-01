/**
 🍪 the_hyp0cr1t3
 🍪 01.01.2021 13:45:53
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

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; int64_t cur, ans = 0; string s;
    cin >> s; n = sz(s);
    
    for(int msk = 0; msk < 1<<n-1; msk++) {
        for(i = cur = 0; i < n-1; i++) {
            cur *= 10; cur += s[i]-'0';
            if(msk>>i&1) ans += cur, cur = 0;
        } cur *= 10; cur += s[i]-'0'; ans += cur;
    } cout << ans << '\n';
} // ~W 