/**
 🍪 the_hyp0cr1t3
 🍪 07.12.2020 21:01:35
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
const int N = 5000 + 5;
int ans[N][N];
int64_t pref[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n; string s, rs;
    cin >> s; n = sz(s);
    rs = s; reverse(all(rs));
    hash_t hash(s), rhash(rs);

    for(i = 0; i < n; i++) {
        for(j = i; ~j; --j) {
            int len = i-j+1 >> 1;
            if(hash(j, j+len-1) == rhash(n-1-i, n-1-(i-len+1)))
                ans[j][i] = min(ans[j][j+len-1], ans[i-len+1][i]) + 1;
        }
    }

    for(i = 0; i < n; i++)
        for(j = i; j < n; j++)
            pref[ans[i][j]]++;
    for(i = N-2; i; i--)
        pref[i] += pref[i+1];

    for(i = 1; i <= n; i++)
        cout << pref[i] << " \n"[i == n];
} // ~W 