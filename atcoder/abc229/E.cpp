/**
 🍪 the_hyp0cr1t3
 🍪 27.11.2021 17:45:16
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for(i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g[--u].push_back(--v);
        g[v].push_back(u);
    }

    int comp = 0;
    vector<int> par(n + 1, -1);
    auto get_par = [&par](int A) {
        while(par[A] >= 0) {
            if(par[par[A]] >= 0)
                par[A] = par[par[A]];
            A = par[A];
        } return A;
    };

    auto merge = [&get_par, &par](int A, int B) {
        A = get_par(A); B = get_par(B);
        if(A == B) return false;
        if(-par[A] < -par[B]) swap(A, B);
        par[A] += par[B]; par[B] = A;
        return true;
    };

    vector<int> ans(n);
    for(i = n - 1; ~i; i--) {
        ans[i] = comp;
        comp++;
        for(auto& x: g[i])
            if(x > i) comp -= merge(i, x);
    }

    for(auto& x: ans)
        cout << x << '\n';
} // ~W