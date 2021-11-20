/**
 🍪 the_hyp0cr1t3
 🍪 20.11.2021 17:56:59
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int64_t expo(int64_t A, int64_t B, int64_t MOD) {
    A %= MOD;
    int64_t res{1}; while(B) {
        if(B & 1) res = res * A % MOD;
        B >>= 1; A = A * A % MOD;
        assert(res >= 0);
    } return res;
}

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int MOD = 998244353;
    int64_t n, k, m;
    cin >> n >> k >> m;
    cout << expo(m, expo(k, n, MOD - 1) + MOD - 1, MOD);
} // ~W