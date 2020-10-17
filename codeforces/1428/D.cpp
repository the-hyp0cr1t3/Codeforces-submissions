/**
 🍪 the_hyp0cr1t3
 🍪 17.10.2020 20:09:40
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

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int a[N];

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, n; array<int, 4> cnt{};
    cin >> n;
    vector<int> columns, threes; columns.reserve(n);
    set<pair<int, int>> ans;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
        if(a[i]) columns.pb(i);
        if(a[i] == 3) threes.pb(i);
    }

    auto kek = []() {
        cout << -1;
        exit(0);
    };

    if(cnt[2] > cnt[1]) kek();

    vector<int> marked(n+1);
    vector<pair<int, int>> ones;
    int currow = n-cnt[1]+1;
    for(i = 0; i < sz(columns); i++) {
        int j = columns[i];
        if(a[j] != 1) continue;
        ans.insert({currow, j});
        ones.pb(currow, j);
        marked[j] = currow++;
    }

    vector<pair<int, int>> free;
    reverse(all(ones));
    for(i = 0; i < sz(columns); i++) {
        int j = columns[i];
        if(a[j] != 2) continue;
        while(sz(ones) and ones.back().second < j) ones.pop_back();
        if(ones.empty()) kek();
        ans.insert({ones.back().first, j});
        marked[j] = ones.back().first;
        free.pb(ones.back().first, j);
        ones.pop_back();
    }
    free.insert(free.end(), all(ones));
    sort(all(free), [](const auto& A, const auto& B) { 
        return A.second < B.second;
    });
    // tr(free);
    // sort(all(free), [](const auto& A, const auto& B) { 
        // return A.first < B.first;
    // });
    currow = 1;
    for(i = 0; i+1 < sz(threes); i++) {
        int j = threes[i];
        ans.insert({currow, j});
        ans.insert({currow, threes[i+1]});
        currow++;
    }

    reverse(all(free));
    if(i < sz(threes)) {
        int j = threes[i];
        while(sz(free) and free.back().second < j) free.pop_back();
        if(free.empty()) kek();
        ans.insert({currow, j});
        ans.insert({currow, free.front().second});
    }

    cout << sz(ans) << '\n';
    for(auto [u, v]: ans) cout << u << ' ' << v << '\n';
}