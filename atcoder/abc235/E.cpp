/**
 🍪 the_hyp0cr1t3
 🍪 15.01.2022 17:51:52
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, n, m, q;
    cin >> n >> m >> q;

    vector<array<int, 4>> edges;
    edges.reserve(m + q);
    while(m--) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v, -1});
    }

    for(i = 0; i < q; i++) {
        int u, v, w; cin >> u >> v >> w;
        edges.push_back({w, u, v, i});
    }

    sort(edges.begin(), edges.end());

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

    vector<bool> ans(q);
    for(auto& [w, u, v, idx]: edges) {
        if(~idx)
            ans[idx] = get_par(u) ^ get_par(v);
        else
            merge(u, v);
    }

    for(auto x: ans)
        cout << (x? "Yes" : "No") << '\n';

} // ~W