/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2021 16:32:08
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    namespace r = ranges; namespace v = views;

    int i, n;
    cin >> n;
    vector<int> a(n), b(n);
    for(auto& x: a) cin >> x;
    for(auto& x: b) cin >> x;
    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);

    auto _ = v::iota(0, n);
    set<int> alive(_.begin(), _.end());

    vector<int> d(n + 1); d[n] = 1;
    vector<pair<int, int>> par(n + 1);
    queue<int> q; q.push(n);
    while(q.size()) {
        i = q.front(); q.pop();
        alive.erase(i);
        if(i - a[i] == 0) {
            cout << d[i] << '\n';
            vector<int> ans{ 0 };
            while(i ^ n) {
                ans.push_back(par[i].first);
                i = par[i].second;
            }

            for(auto x: ans | v::reverse)
                cout << x << ' ';
            return 0;
        }

        for(auto it = alive.lower_bound(i - a[i]);
                it != alive.end() and *it <= i; it = alive.erase(it)) {
            if(!d[*it + b[*it]]) {
                d[*it + b[*it]] = d[i] + 1;
                par[*it + b[*it]] = { *it, i };
                q.push(*it + b[*it]);
            }
        }
    }

    cout << -1 << '\n';
} // ~W