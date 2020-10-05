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

int genbase(int l, int r) {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int base = uniform_int_distribution<int>(l+1, r-1)(rng);
    return base&1? base : base-1;
}

struct hash_t {
    static const int mod = 1e9+123;
    static int base;
    static vector<int> pow1;
    static vector<uint64_t> pow2;
    vector<int> suf1;
    vector<uint64_t> suf2;

    hash_t(const string& s): suf1(sz(s)+1), suf2(sz(s)+1) {
        assert(base < mod); const int n = sz(s);
        pow1.reserve(n+1); pow2.reserve(n+1);
        while(sz(pow1) <= n) {
            pow1.pb(1LL * pow1.back() * base % mod);
            pow2.pb(pow2.back() * base);
        }

        for(int i = n-1; ~i; i--) {
            suf1[i] = (1ll * suf1[i+1] * base + s[i]) % mod;
            suf2[i] = suf2[i+1] * base + s[i];
        }
    }

    pair<int, uint64_t> operator()(int l, int r) {
        int res1 = suf1[l] - 1ll * suf1[r+1] * pow1[r-l+1] % mod;
        res1 = res1 < 0? res1 + mod : res1;
        uint64_t res2 = suf2[l] - suf2[r+1] * pow2[r-l+1];
        return {res1, res2};
    }
};
int hash_t::base = genbase(256, hash_t::mod);
vector<int> hash_t::pow1{1};
vector<uint64_t> hash_t::pow2{1};

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, k, cnt; string s, t;
    cin >> s >> t >> k; n = sz(s);
    hash_t hsh(s);

    set<pair<int, uint64_t>> us;
    for(i = 0; i < n; i++) {
        for(j = i, cnt = 0; ~j; j--) {
            cnt += t[s[j]-'a'] == '0';
            if(cnt > k) break;
            us.insert(hsh(j, i));
        }
    } cout << sz(us) << '\n';
}