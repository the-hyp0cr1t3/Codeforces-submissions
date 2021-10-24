/**
 🍪 the_hyp0cr1t3
 🍪 24.10.2021 15:39:43
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int64_t INF = 1e18;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, k, n, K = 0, ans = 1;
        cin >> n;
        vector<int> a(n);
        for(i = 0; auto& x: a) {
            cin >> x;
            if(1LL * i * (i + 1) / 2 <= n)
                K = i;
            i++;
        }

        K += 5;
        vector<int64_t> best(n + 1), pref(n + 1);
        for(i = 1; i <= n; i++) {
            best[i] = a[i - 1];
            pref[i] = pref[i  - 1] + a[i - 1];
        }

        for(k = 2; k <= K and k <= n; k++) {
            vector<int64_t> nbest(n + 1);
            int64_t mx = 0;
            for(i = n - k ; i; i--) {
                mx = max(mx, best[i + k]);
                if(auto s = pref[i + k - 1] - pref[i - 1]; s < mx)
                    nbest[i] = s;
            }

            best = std::move(nbest);
            if(!*ranges::max_element(best))
                break;
        }

        cout << k - 1 << '\n';
    }();

} // ~W