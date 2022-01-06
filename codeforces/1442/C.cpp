/**
 🍪 the_hyp0cr1t3
 🍪 06.01.2022 17:40:40
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

const int MOD = 998244353, K = 20;
template<typename T>
T expo(T A, int64_t B) {
    T res{1}; while(B) {
        if(B & 1) res = res * A % MOD;
        B >>= 1; A = A * A % MOD;
    } return res;
}

struct state {
    int v, k, d;
    state() = default;
    state(int v, int k, int d)
        : v(v), k(k), d(d) {}
    int64_t dist() const { return (1LL << k) - 1 + d; }
    std::strong_ordering operator<=>(const state& o) const {
        return max(k, o.k) < K? dist() <=> o.dist()
                                    : pair(k, d) <=> pair(o.k, o.d);
    }
};

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

    int i, j, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), rg(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        rg[v].push_back(u);
    }

    vector<vector<state>> d(n, vector<state>(K + 2));
    for(i = 0; i < n; i++) {
        for(j = 0; j < K; j++)
            d[i][j] = state(i, j, 1e9);
        d[i][K] = d[i][K + 1] = state(i, 1e9, 1e9);
    }

    priority_queue<state, vector<state>, greater<state>> pq;
    pq.emplace(d[0][0] = state(0, 0, 0));

    while(!pq.empty()) {
        state top = pq.top(); pq.pop();
        int kk = min(K + (top.k & 1), top.k);
        if(d[top.v][kk] < top) continue;
        const auto& G = top.k & 1? rg : g;
        for(auto& to: G[top.v])
            if(chmin(d[to][kk], state(to, top.k, top.d + 1)))
                pq.emplace(d[to][kk]);
        top.k++;
        kk = min(K + (top.k & 1), top.k);
        if(chmin(d[top.v][kk], top))
            pq.emplace(d[top.v][kk]);
    }

    int64_t ans = 2e18;
    for(i = 0; i < K; i++)
        if(d[n - 1][i].d < 1e9)
            ans = min(ans, d[n - 1][i].dist());
    if(ans == 2e18) {
        auto best = min(d[n - 1][K], d[n - 1][K + 1]);
        ans = expo(2LL, best.k) + best.d + MOD - 1;
    }

    cout << ans % MOD;
} // ~W