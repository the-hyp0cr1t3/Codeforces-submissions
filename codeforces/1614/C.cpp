/**
 🍪 the_hyp0cr1t3
 🍪 26.11.2021 17:00:20
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<typename T>
T expo(T A, int64_t B, int MOD) {
    T res{1}; while(B) {
        if(B & 1) res = res * A % MOD;
        B >>= 1; A = A * A % MOD;
    } return res;
}

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int MOD = 1e9 + 7;

    int tests; cin >> tests;
    while(tests--) [&MOD]() {
        int i, n, m; int64_t OR = 0;
        cin >> n >> m;
        while(m--) {
            int l, r, x;
            cin >> l >> r >> x;
            OR |= x;
        }

        cout << expo(2LL, n - 1, MOD) * OR % MOD << '\n';
    }();

} // ~W