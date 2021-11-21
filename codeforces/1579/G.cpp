/**
 🍪 the_hyp0cr1t3
 🍪 21.11.2021 15:47:36
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
    const int N = 2000 + 5;

    int tests; cin >> tests;
    while(tests--) [&]() {
        array<int, N> dp;
        dp.fill(N); dp[0] = 0;

        int i, n; cin >> n;
        while(n--) {
            int a; cin >> a;
            array<int, N> ndp;
            ndp.fill(N);

            for(i = 0; i < N; i++) {
                if(i + a < N)
                    chmin(ndp[i + a], max(i + a, dp[i]));
                chmin(ndp[max(0, i - a)], dp[i] + max(0, a - i));
            }

            dp = std::move(ndp);
        }

        cout << *r::min_element(dp) << '\n';
    }();

} // ~W