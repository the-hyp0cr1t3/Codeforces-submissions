/**
 🍪 the_hyp0cr1t3
 🍪 23.11.2021 20:16:50
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
        int i, j, n;
        cin >> n;
        vector<int> a(n);
        for(auto& x: a) cin >> x;
        for(i = 0, j = n - 1; i < j; i++, j--)
            if(a[i] ^ a[j]) break;

        auto Try = [&](int x) {
            vector<int> b;
            b.reserve(n);
            for(auto& v: a)
                if(v ^ x) b.push_back(v);
            for(int p = 0, q = b.size() - 1; p < q; p++, q--)
                if(b[p] ^ b[q]) return false;
            return true;
        };

        cout << (i >= j or Try(a[i]) or Try(a[j])? "yEs" : "nO") << '\n';
    }();

} // ~W