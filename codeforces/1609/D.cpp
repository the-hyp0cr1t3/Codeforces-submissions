/**
 🍪 the_hyp0cr1t3
 🍪 28.11.2021 20:58:52
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

struct DSU {
    int n, components;
    vector<int> data, rootID, roots;

    DSU(int n): n(n), components(n), data(n + 1, -1), rootID(n + 1, -1) {}

    int par(int x) {
        return data[x] < 0? x : data[x] = par(data[x]);
    }

    int SZ(int x) {
        return -data[par(x)];
    }

    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; components--;
        return true;
    }

    void getRoots() {
        roots.reserve(components);
        for(int i = 0; i < n; i++) {
            if(data[i] < 0) {
                rootID[i] = roots.size();
                roots.push_back(i);
            }
        }
    }

};

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, j, n, q;
    cin >> n >> q;
    vector<pair<int, int>> edges;
    for(i = 1; i <= q; i++) {
        int u, v; cin >> u >> v;
        edges.emplace_back(--u, --v);

        DSU dsu(n);
        int extra = 0;
        for(auto& [x, y]: edges)
            extra += !dsu.merge(x, y);
        dsu.getRoots();

        r::sort(dsu.roots, [&](int A, int B) {
            return -dsu.data[A] > -dsu.data[B];
        });

        int ans = -1;
        for(j = 0; j <= extra; j++)
            ans += -dsu.data[dsu.roots[j]];

        cout << ans << '\n';
    }

} // ~W