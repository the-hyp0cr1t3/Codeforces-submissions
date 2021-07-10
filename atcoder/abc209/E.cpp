/**
 🍪 the_hyp0cr1t3
 🍪 10.07.2021 17:50:39
**/
#ifdef W
    #include "k_II.h"
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

struct edge_t {
    int u{-1}, v{-1};
    edge_t(int u, int v) : u(u), v(v) {}
    friend ostream& operator<<(ostream& os, const edge_t& e) { os << e.u << ' ' << e.v; return os; }
};

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, n;
    cin >> n;

    int m = 0;
    auto get_id = [&m, mp = map<string, int>()](string s) mutable {
        if(!mp.count(s)) mp[s] = m++;
        return mp[s];
    };

    vector<edge_t> edges; edges.reserve(n);
    for(i = 0; i < n; i++) {
        string s; cin >> s;
        edges.pb(get_id(s.substr(0, 3)),
                    get_id(s.substr(sz(s)-3)));
    }

    vector<int> outdeg(m);
    vector<vector<int>> rg(m);
    for(auto& e: edges) {
        rg[e.v].pb(e.u);
        outdeg[e.u]++;
    }

    queue<int> q;
    vector<int> win(m), vis(m);
    for(i = 0; i < m; i++)
        if(!outdeg[i]) q.push(i);
    while(!q.empty()) {
        auto v = q.front(); q.pop(); vis[v] = true;
        for(auto& x: rg[v]) {
            if(!vis[x] and (!--outdeg[x] or !win[v]))
                vis[x] = true, q.push(x), win[x] |= win[v] ^ 1;
        }
    }

    for(i = 0; i < n; i++)
        cout << (vis[edges[i].v]? win[edges[i].v]? "Aoki" : "Takahashi" : "Draw") << '\n';
} // ~W