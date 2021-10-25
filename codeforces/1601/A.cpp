/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 14:30:21
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

// This covers up to 2^64. See http://oeis.org/A066150 and http://oeis.org/A036451
const int FACTORS_MAX = 185000;

vector<int64_t> generate_factors(const vector<pair<int64_t, int>> &prime_factors, bool sorted = false) {
    static int64_t buffer[FACTORS_MAX];
    int product = 1;

    for(auto &pf : prime_factors)
        product *= pf.second;

    vector<int64_t> factors = {1};
    factors.reserve(product);

    for(auto &pf : prime_factors) {
        int64_t p = pf.first;
        int exponent = pf.second;
        int before_size = int(factors.size());

        for(int i = 0; i < exponent * before_size; i++)
            factors.push_back(factors[factors.size() - before_size] * p);

        if(sorted && factors[before_size - 1] > p)
            for(int section = before_size; section < int(factors.size()); section *= 2)
                for(int i = 0; i + section < int(factors.size()); i += 2 * section) {
                    int length = min(2 * section, int(factors.size()) - i);
                    merge(factors.begin() + i, factors.begin() + i + section, factors.begin() + i + section, factors.begin() + i + length, buffer);
                    copy(buffer, buffer + length, factors.begin() + i);
                }
    }
    return factors;
}

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int LG = 30, N = LG * 2e5 + 1;

    array<int, N> spf; iota(spf.begin(), spf.end(), 0);
    vector<int> primes{2}; primes.reserve(N);
    for(int z = 4; z < N; z += 2) spf[z] = 2;
    for(int z = 3; z*z < N; z += 2) if(spf[z] == z) {
        for(int y = z*z; y < N; y += z*2)
            if(spf[y] == y) spf[y] = z;
    }
    for(int z = 3; z < N; z += 2)
        if(spf[z] == z) primes.push_back(z);

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, j, n;
        cin >> n;
        array<int, LG> cnt{};
        for(i = 0; i < n; i++) {
            int a; cin >> a;
            for(j = 0; j < LG; j++)
                cnt[j] += a >> j & 1;
        }

        int g = 0;
        for(i = 0; i < LG; i++)
            g = gcd(g, cnt[i]);

        if(g == 0) {
            for(i = 1; i <= n; i++)
                cout << i << " \n"[i == n];
        } else {
            vector<pair<int64_t, int>> pfs;
            pfs.reserve(10);
            while(g > 1) {
                int p = spf[g], c = 0;
                while(spf[g] == p)
                    g /= p, c++;
                pfs.emplace_back(p, c);
            }

            for(i = 0; auto x: generate_factors(pfs, true))
                cout << x << ' ';
            cout << '\n';
        }

    }();

} // ~W