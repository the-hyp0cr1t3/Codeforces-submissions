/**
 🍪 the_hyp0cr1t3
 🍪 10.11.2020 14:13:20
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
    int i, n; string s;
    cin >> s; n = sz(s);
    
    if(s == string(n, s[0]))
        return cout << n << '\n' << 1 << '\n', 0;

    auto generate_pi = [&] (const string& s) {
        // s = (pattern + '#' + text) 
        int n = sz(s);
        vector<int> pi(n);
        for(i = 1; i < n; i++) {
            int p = pi[i-1];
            while(p and s[i] != s[p]) p = pi[p-1];
            pi[i] = p + (s[i] == s[p]);
        }
        return pi;
    };

    auto check = [](int len, int pi) {
        return pi and len % (len - pi) == 0;
    };

    auto pref = generate_pi(s);
    reverse(all(s));
    auto suf = generate_pi(s);
    reverse(all(s)); reverse(all(suf));

    if(!check(n, pref[n-1]))
        return cout << 1 << '\n' << 1 << '\n', 0;

    int ans = 0;
    for(i = 0; i < n-1; i++)
        ans += !check(i+1, pref[i]) and !check(n-1-i, suf[i+1]);

    cout << 2 << '\n' << ans << '\n';
} // ~W