/**
 🍪 the_hyp0cr1t3
 🍪 18.09.2021 20:06:33
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif
#define pb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) static_cast<int32_t>(x.size())

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int Q; cin >> Q;

    while(Q--) []() {
        int i, n;
        cin >> n;
        vector<int> indeg(n);
        vector<vector<int>> a(n), g(n);
        for(i = 0; i < n; i++) {
            int k; cin >> k;
            indeg[i] = k;
            while(k--) {
                int x; cin >> x;
                a[i].pb(--x);
                g[x].pb(i);
            }
        }

        set<int> open;
        for(i = 0; i < n; i++)
            if(!indeg[i]) open.insert(i);

        int cur = n, ans = 0, left = n;
        while(!open.empty()) {
            auto it = open.lower_bound(cur);
            if(it == open.end()) {
                cur = 0, ans++;
            } else {
                cur = *it; left--;
                open.erase(it);
                for(auto& x: g[cur])
                    if(!--indeg[x]) open.insert(x);
            }
        }

        cout << (left? -1 : ans) << '\n';
    }();

} // ~W