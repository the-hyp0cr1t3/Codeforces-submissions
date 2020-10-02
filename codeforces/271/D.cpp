/**
 🍪 the_hyp0cr1t3
 🍪 03.10.2020 03:34:15
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

struct Hashs {
    int n, p, mod;
    vector<int> hashs, pows;

    Hashs(string& s, int p, int mod): p(p), mod(mod) {
        n = sz(s); hashs.resize(n+1); pows.resize(n+1, 1);
        for(int i = n-1; ~i; i--) {
            hashs[i] = (1ll * hashs[i+1] * p + s[i]-'a'+1) % mod;
            pows[n-i] = 1ll * pows[n-i-1] * p % mod;
        } pows[n] = 1ll * pows[n-1] * p % mod;
    }

    int gethash(int l, int r) {
        int res = hashs[l] - 1ll * hashs[r+1] * pows[r-l+1] % mod;
        return res < 0? res + mod : res;
    }
};

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, k, cnt; string s, t;
    cin >> s >> t >> k; n = sz(s);
    Hashs hsh1(s, 37, 1e9+7);
    Hashs hsh2(s, 41, 1e9+21);

    set<pair<int, int>> us;
    for(i = 0; i < n; i++) {
        for(j = i, cnt = 0; ~j; j--) {
            cnt += t[s[j]-'a'] == '0';
            if(cnt > k) break;
            us.insert({hsh1.gethash(j, i), hsh2.gethash(j, i)});
        }
    } cout << sz(us) << '\n';
}