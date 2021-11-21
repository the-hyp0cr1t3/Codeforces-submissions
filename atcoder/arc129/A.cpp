/**
 🍪 the_hyp0cr1t3
 🍪 21.11.2021 17:32:04
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace rr = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int64_t n, l, r, ans = 0;
    cin >> n >> l >> r; ++r;

    auto get = [l, r](int64_t x) {
        return max(l, min(r, x));
    };

    for(int i = 0; i < 63; i++)
        if(n >> i & 1)
            ans += get(1LL << i + 1) - get(1LL << i);

    cout << ans;
} // ~W