/**
 🍪 the_hyp0cr1t3
 🍪 10.01.2022 15:08:11
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
    auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
    const int N = 2e5, A = 451;

    int n, q;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    vector<vector<int>> dp(n, vector<int>(A + 1));
    Y([&](auto dfs, int v, int p) -> void {
        for(auto& x: g[v]) if(x ^ p) {
            dfs(x, v);
            for(int i = 0; i <= A; i++)
                dp[v][i] += max(1, dp[x][i] - i);
        }
    })(0, -1);

    cin >> q;
    vector<int> ans(q);
    vector<tuple<int, int, int>> queries;
    for(int i = 0; i < q; i++) {
        int v, k; cin >> v >> k; --v;
        if(k <= A) ans[i] = dp[v][k];
        else queries.emplace_back(v, k, i);
    }

    Y([&](auto dfs, int v, int p) -> void {
        dp[v] = { 0, 0 };
        for(auto& x: g[v]) if(x ^ p) {
            dfs(x, v);
            int m = min<int>(A + 2, dp[v].size() + dp[x].size() + 2);
            vector<int> ndp = dp[v];
            ndp.resize(m + 1, 0);
            for(int i = 0; i < dp[v].size(); i++) {
                for(int j = 0; j + i < m and j < dp[x].size(); j++) {
                    chmax(ndp[i + j], dp[v][i] + 1);
                    chmax(ndp[i + j + 1], dp[x][j] + dp[v][i]);
                }
            }
            dp[v] = std::move(ndp);
        }
    })(0, -1);

    for(auto& [v, k, idx]: queries)
        for(int i = 0; i < dp[v].size(); i++)
            ans[idx] = max(ans[idx], dp[v][i] - k * i);

    for(auto x: ans) cout << x << '\n';
} // ~W