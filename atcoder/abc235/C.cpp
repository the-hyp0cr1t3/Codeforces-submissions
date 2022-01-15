/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 17:34:05
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

    int i, n, q;
    cin >> n >> q;
    map<int, vector<int>> occ;
    for(i = 1; i <= n; i++) {
        int x; cin >> x;
        occ[x].push_back(i);
    }

    while(q--) {
        int x, k; cin >> x >> k;
        cout << (!occ.count(x) or occ[x].size() < k? -1 : occ[x][k - 1]) << '\n';
    }

} // ~W