/**
 🍪 the_hyp0cr1t3
 🍪 12.12.2021 21:22:59
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n;
        cin >> n;
        vector<int> a(n), pos(n), cnt(n);
        for(auto& x: a) cin >> x, --x;

        for(i = 0; i < n; i++)
            pos[a[i]] = i, cnt[a[i]]++;

        if(*R::max_element(cnt) > 1)
            return cout << "yEs" << '\n', 0;

        auto apply = [&](int x, int y, int z) {
            int p = a[x], q = a[y], r = a[z];
            a[x] = q; pos[q] = x;
            a[y] = r; pos[r] = y;
            a[z] = p; pos[p] = z;
        };

        for(i = 0; i + 2 < n; i++) {
            if(a[i] == i) continue;
            apply(i, pos[i], n - 1 - (pos[i] == n - 1));
        }

        return cout << (R::is_sorted(a)? "yEs" : "nO") << '\n', 0;
    }();

} // ~W