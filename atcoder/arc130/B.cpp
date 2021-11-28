/**
 🍪 the_hyp0cr1t3
 🍪 28.11.2021 17:33:54
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

    int i, n, m, c, q;
    cin >> n >> m >> c >> q;
    vector<tuple<int, int, int>> queries(q);
    for(auto& [x, y, z]: queries)
        cin >> x >> y >> z, z--;

    set<int> rows, cols;
    vector<int64_t> ans(c);
    reverse(queries.begin(), queries.end());
    for(auto& [t, idx, col]: queries) {
        if(t == 1) {
            auto [it, b] = rows.insert(idx);
            if(b) ans[col] += m - cols.size();
        } else {
            auto [it, b] = cols.insert(idx);
            if(b) ans[col] += n - rows.size();
        }
    }

    for(auto& x: ans)
        cout << x << ' ';
} // ~W