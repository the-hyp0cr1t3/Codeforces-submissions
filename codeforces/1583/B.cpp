/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2021 22:11:32
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n, m;
        cin >> n >> m;
        vector<int> vis(n);
        while(m--) {
            int a, b, c; cin >> a >> b >> c;
            vis[--b]++;
        }

        int root = min_element(vis.begin(), vis.end()) - vis.begin();
        for(i = 0; i < n; i++)
            if(i ^ root) cout << i + 1 << ' ' << root + 1 << '\n';

    }();

} // ~W