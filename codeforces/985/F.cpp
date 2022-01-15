/**
 🍪 the_hyp0cr1t3
 🍪 06.01.2022 23:31:00
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

namespace Hashing {
    constexpr int _mod = 1e9+123;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static const int _base = uniform_int_distribution<int>(256, _mod-2)(rng) | 1;
    using hash_t = pair<int, uint64_t>;
    vector<uint64_t> pow2{1};

    template<const int& base = _base, int mod = _mod>
    struct double_hash {
        static inline vector<int> pow1{1};
        int n;
        vector<int> suf1;
        vector<uint64_t> suf2;

        void build(const string& s, char c) {
            n = s.size();
            assert(base < mod);
            suf1.resize(n + 1); suf2.resize(n + 1);
            pow1.reserve(n+1); pow2.reserve(n+1);
            while((int)pow1.size() <= n)
                pow1.push_back(1LL * pow1.back() * base % mod);
            while((int)pow2.size() <= n)
                pow2.push_back(pow2.back() * base);
            for(int i = n-1; ~i; i--) {
                suf1[i] = (1ll * suf1[i+1] * base + (s[i] == c)) % mod;
                suf2[i] = suf2[i+1] * base + (s[i] == c);
            }
        }

        hash_t operator()(int l, int r) const {
            int res1 = suf1[l] - 1ll * suf1[r+1] * pow1[r-l+1] % mod;
            res1 = res1 < 0? res1 + mod : res1;
            uint64_t res2 = suf2[l] - suf2[r+1] * pow2[r-l+1];
            return {res1, res2};
        }
        hash_t operator()() const { return (*this)(0, n-1); }
    };

}

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int M = 26;

    int i, n, q; string s;
    cin >> n >> q >> s;

    array<Hashing::double_hash<>, M> hsh;
    for(i = 0; i < M; i++)
        hsh[i].build(s, 'a' + i);

    vector<array<int, M>> nxt(n + 1);
    nxt[n].fill(n);
    for(i = n - 1; ~i; i--) {
        nxt[i] = nxt[i + 1];
        nxt[i][s[i] - 'a'] = i;
    }

    while(q--) {
        int x, y, len; cin >> x >> y >> len;
        --x; --y;

        bool bad = false;
        for(auto _: {0, 1}) {
            for(i = 0; !bad and i < M; i++)
                if(nxt[x][i] < x + len)
                    bad |= hsh[s[nxt[x][i]] - 'a'](x, x + len - 1)
                            != hsh[s[y + nxt[x][i] - x] - 'a'](y, y + len - 1);
            swap(x, y);
        }

        cout << (bad? "NO" : "YES") << '\n';
    }

} // ~W