/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 15:50:31
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

    DSU(int n): n(n), components(n), data(n + 1, -1) {}

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
    int i, n, m1, m2;
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

    auto go = []() {

    };

    queue<int> q1, q2;
    cout << n - 1 - max(m1, m2) << '\n';
    for(i = 2; i <= n; i++) {
        if(!a.same(1, i) and !b.same(1, i))
            a.merge(1, i), b.merge(1, i), cout << 1 << ' ' << i << '\n';
        if(!a.same(1, i))
            q1.push(i);
        if(!b.same(1, i))
            q2.push(i);
    }

    while(!q1.empty() and !q2.empty()) {
        int u = q1.front(), v = q2.front();
        if(a.same(1, u) and b.same(1, u)) {
            q1.pop(); continue;
        }
        if(a.same(1, v) and b.same(1, v)) {
            q2.pop(); continue;
        }
        a.merge(u, v); b.merge(u, v);
        cout << u << ' ' << v << '\n';
        q1.pop(); q2.pop();
    }

} // ~W