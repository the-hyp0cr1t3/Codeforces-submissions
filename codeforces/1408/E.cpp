/**
 🍪 the_hyp0cr1t3
 🍪 01.10.2020 16:48:18
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
    int u, v, w;
    edge_t() = default;
    edge_t(int u, int v, int w) : u(u), v(v), w(w) {}
    bool operator<(const edge_t& other) { return w > other.w; }
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v << ' ' << e.w; return os; }
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
int a[N], b[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n, m;
    cin >> m >> n;
    for(i = 0; i < m; i++)
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    vector<edge_t> edges;
    edges.reserve(N);
    for(i = 0; i < m; i++) {
        int x, t; cin >> t;
        while(t--) {
            cin >> x; --x;
            edges.pb(n+i, x, a[i]+b[x]);
        }
    } sort(all(edges));

    vector<int> data(n+m, -1);
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
    
    int64_t ans = 0;
    for(auto& e: edges)
        if(!merge(e.u, e.v)) ans += e.w;

    cout << ans << '\n';
}