#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define ins insert
#define sz(a) (int)(a).size()
const int N = 2000 + 5;

struct dsu {
    int n, parent[N], node[N];
    set <int> roots;
    dsu (int Q) : n(Q) {
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            node[i] = 1;
        }
    }
    int findparent (int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = findparent(parent[x]);
    }
    void merge (int x, int y) {
        x = findparent(x);
        y = findparent(y);
        if (x == y) return;
        if (node[x] > node[y])
            parent[y] = x, node[x] += node[y];
        else
            parent[x] = y, node[y] += node[x];
    }
    bool same (int x, int y) {
        return findparent(x) == findparent(y);
    }
    bool only (int x) {
        return node[findparent(x)] == 1;
    }
    int CountDisjSets (int start, int end) {
        for(int i = start; i < end; i++) 
            roots.ins(findparent(i));
        return sz(roots);
    }
};

int32_t main() {
    IOS;
    int i, n, m, t, v;
    cin >> n >> m;
    dsu g(n+m+1);
    bool nogood = 1;
    for(i = 0; i < n; i++) {
        cin >> t;
        while (t--) {
            nogood = 0;
            cin >> v;  
            v--; 
            g.merge(i, n+v);
        }
    }
    if (nogood) return cout << n, 0;
    cout << g.CountDisjSets(0, n) - 1;
    return 0;
}