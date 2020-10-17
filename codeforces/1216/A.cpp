/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 13:53:20
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

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, ans = 0; string s;
    cin >> n >> s;
    
    for(i = 0; i < n; i+=2)
        if(s[i] == s[i+1]) 
            ans++, s[i] = char(((s[i]-'a')^1)+'a');

    cout << ans << '\n' << s << '\n';
}