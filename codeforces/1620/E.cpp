/**
 🍪 the_hyp0cr1t3
 🍪 18.12.2021 22:32:41
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

struct DSU {
    int n; vector<int> data, head;

    DSU(int n): n(n), data(n, -1), head(n) {
        iota(head.begin(), head.end(), 0);
    }

    int par(int x) {
        return data[x] < 0? x : data[x] = par(data[x]);
    }
    int SZ(int x) { return -data[par(x)]; }
    int& col(int x) { return head[par(x)]; }

    bool merge(int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        return true;
    }

};


int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    const int N = 5e5 + 5;

    array<int, N> pos;
    pos.fill(-1);

    DSU dsu(N);
    int i, q, n = 0;
    cin >> q;

    while(q--) {
        int t, x, y; cin >> t >> x;
        if(t == 1) {
            if(~pos[x]) dsu.merge(n, pos[x]);
            dsu.col(n) = x;
            pos[x] = n++;
        } else {
            cin >> y;
            if(~pos[x] and x ^ y) {
                if(~pos[y]) dsu.merge(pos[x], pos[y]);
                pos[y] = exchange(pos[x], -1);
                dsu.col(pos[y]) = y;
            }
        }
    }

    for(i = 0; i < n; i++)
        cout << dsu.col(i) << ' ';
} // ~W