/**
 🍪 the_hyp0cr1t3
 🍪 30.09.2020 16:03:10
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()

struct edge_t {
    int u, v, time;
    edge_t() = default;
    edge_t(int u, int v, int time) : u(u), v(v), time(time) {}
    bool operator<(const edge_t& other) { return time < other.time; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.time; return os; }
};

struct Query {
    int x, time;
    vector<pair<int, int>> people;
    Query() = default;
    Query(int time, int x): time(time), x(x) {}
};

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n, Q;
    cin >> n >> Q;
    vector<vector<int>> g(n);
    vector<int> outdeg(n);
    vector<edge_t> edges;
    edges.reserve(n);
    vector<Query> queries;
    queries.reserve(Q);

    for(i = 0; i < Q; i++) {
        int t, x; cin >> t >> x; --x;
        if(t == 1) {
            int y; cin >> y;
            g[--y].pb(x); edges.pb(x, y, i);
            outdeg[x]++;
        } else if(t == 2) {
            queries.pb(i, x);
        } else {
            int q; cin >> q;
            queries[--q].people.pb(x, i);
        }
    }

    vector<int> tin(n), tout(n);
    int tim = 0;
    auto dfs = Y([&](auto self, int v) -> void {
        tin[v] = ++tim;
        for(auto& x: g[v]) self(x);
        tout[v] = tim;
    });
    
    for(i = 0; i < n; i++) if(!outdeg[i]) dfs(i);

    auto isAnc = [&](int p, int v) {
        return tin[p] <= tin[v] and tout[v] <= tout[p];
    };

    vector<int> data(n+1, -1);
    auto par = Y([&](auto self, int pp) -> int {
        return data[pp] < 0 ? pp : data[pp] = self(data[pp]);
    });
    
    auto merge = [&](int x, int y) {
        x = par(x); y = par(y);
        if(x == y) return false;
        if(-data[x] < -data[y]) swap(x, y);
        data[x] += data[y]; data[y] = x;
        return true;
    };
    
    vector<pair<int, string>> ans;
    ans.reserve(Q);
    auto process = [&](Query& q) {
        for(auto& [p, time]: q.people)
            ans.pb(time, par(q.x) == par(p) and isAnc(p, q.x)? "YES" : "NO");
    };

    for(i = j = 0; i < sz(edges); i++) {
        while(j < sz(queries) and queries[j].time < edges[i].time)
            process(queries[j++]);
        merge(edges[i].u, edges[i].v);
    }
    while(j < sz(queries))
        process(queries[j++]);

    sort(all(ans));
    for(auto& [t, s]: ans) cout << s << '\n';
}