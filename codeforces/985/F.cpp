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
    constexpr int _mod = 1e9 + 123;
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    static const int _base = uniform_int_distribution<int>(256, _mod - 2)(rng) | 1;

    template<const int& base = _base, int mod = _mod>
    struct single_hash {
        static inline vector<int> pows{1};
        int n;
        vector<int> suf;
        void build(const string& s, char c) {
            n = s.size();
            assert(base < mod);
            suf.resize(n + 1); pows.reserve(n + 1);
            while(pows.size() <= n)
                pows.push_back(1LL * pows.back() * base % mod);
            for(int i = n - 1; ~i; i--)
                suf[i] = (1ll * suf[i + 1] * base + (s[i] == c)) % mod;
        }

        // hash [l, r) 0-based
        int operator()(int l, int r) const {
            int res = suf[l] - 1ll * suf[r] * pows[r - l] % mod;
            return res < 0? res + mod : res;
        }
        int operator()() const { return (*this)(0, n); }
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

    array<Hashing::single_hash<>, M> hsh;
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
                    bad |= hsh[s[nxt[x][i]] - 'a'](x, x + len)
                            != hsh[s[y + nxt[x][i] - x] - 'a'](y, y + len);
            swap(x, y);
        }

        cout << (bad? "NO" : "YES") << '\n';
    }

} // ~W