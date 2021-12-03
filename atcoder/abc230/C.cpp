/**
 🍪 the_hyp0cr1t3
 🍪 03.12.2021 17:40:15
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int64_t i, j, n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;

    for(i = p; i <= q; i++) {
        for(j = r; j <= s; j++)
            cout << (abs(a - i) == abs(b - j)? '#' : '.');
        cout << '\n';
    }

} // ~W