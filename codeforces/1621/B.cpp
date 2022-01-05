/**
 🍪 the_hyp0cr1t3
 🍪 05.01.2022 16:31:44
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
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
    const int INF = 2e9;

    int tests; cin >> tests;
    while(tests--) [&]() {
        int i, n, l = INF, r = -INF, lc, rc, both = INF;
        cin >> n;
        while(n--) {
            int li, ri, ci;
            cin >> li >> ri >> ci;
            if(chmin(l, li))
                lc = ci, both = INF;
            if(chmax(r, ri))
                rc = ci, both = INF;
            if(li == l) chmin(lc, ci);
            if(ri == r) chmin(rc, ci);
            if(li == l and ri == r)
                chmin(both, ci);
            cout << min(both, lc + rc) << '\n';
        }

    }();

} // ~W