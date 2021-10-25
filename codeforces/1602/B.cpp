/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 21:34:18
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    namespace r = ranges; namespace v = views;

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n;
        cin >> n;
        vector a(1, vector<int>(n));
        for(auto& x: a[0]) cin >> x, --x;

        while(true) {
            vector<int> f(n, -1), b(n);
            for(auto& x: a.back())
                f[x]++;
            for(i = 0; i < n; i++)
                b[i] = f[a.back()[i]];
            if(b == a.back()) break;
            a.push_back(b);
        }

        int q;
        cin >> q;
        while(q--) {
            int pos, k; cin >> pos >> k;
            cout << a[min<int>(a.size() - 1, k)][--pos] + 1 << '\n';
        }

    }();

} // ~W