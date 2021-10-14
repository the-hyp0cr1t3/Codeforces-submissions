/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 12:31:17
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

    DSU(int n): n(n), data(n + 1, -1) {}

    int par(int x) {
        return data[x] < 0? x : data[x] = par(data[x]);
    }

    int SZ(int x) {
        return -data[par(x)];
    }

    bool same(int x, int y) {
        return par(x) == par(y);
    }

    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x; components--;
        return true;
    }

};

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n, m1, m2;
    cin >> n >> m1 >> m2;
    DSU a(n), b(n);
    for(i = 0; i < m1; i++) {
        int u, v; cin >> u >> v;
        a.merge(u, v);
    }

    for(i = 0; i < m2; i++) {
        int u, v; cin >> u >> v;
        b.merge(u, v);
    }

    cout << n - 1 - max(m1, m2) << '\n';
    for(i = 1; i <= n; i++)
        for(j = i + 1; j <= n; j++)
            if(!a.same(i, j) and !b.same(i, j))
                a.merge(i, j), b.merge(i, j), cout << i << ' ' << j << '\n';


} // ~W