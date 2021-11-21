/**
 🍪 the_hyp0cr1t3
 🍪 21.11.2021 13:53:17
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

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;
        if(r::count(a, 1) & 1)
            return cout << "nO" << '\n', 0;

        vector<int> ans;
        ans.reserve(n);

        auto solve = [&](int l, int r) {
            auto apply = [&](int k) {
                int x = a[k] ^ a[k + 1] ^ a[k + 2];
                a[k] = a[k + 1] = a[k + 2] = x;
                ans.push_back(k + 1);
            };

            for(int j = l; j < r; j += 2)
                apply(j);

            for(int j = r - 2; j >= l; j -= 2)
                apply(j);
        };

        if(n & 1) {
            solve(0, n - 1);
        } else {
            int x = 0;
            for(i = 0; i < n; i += 2) {
                x ^= a[i];
                if(!x) break;
                x ^= a[i + 1];
            }

            if(i == n)
                return cout << "nO" << '\n', 0;

            solve(0, i);
            solve(i + 1, n - 1);
        }

        assert(!r::count(a, 1));
        cout << "yEs" << '\n';
        cout << ans.size() << '\n';
        for(auto& x: ans)
            cout << x << ' ';
        cout << '\n';

        return 0;
    }();

} // ~W