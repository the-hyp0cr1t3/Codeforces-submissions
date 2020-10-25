/**
 🍪 the_hyp0cr1t3
 🍪 25.10.2020 23:01:28
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

void kek() {
    cout << "NO" << '\n';
    exit(0);
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    vector<int> adds, ans(2*n), events(2*n);
    vector<pair<int, int>> buys;
    int stock = 0;
    for(i = 0; i < 2*n; i++) {
        char c; cin >> c;
        if(c == '+') {
            stock++;
            adds.pb(i);
            events[i] = 0;
        } else {
            int x; cin >> x;
            if(!stock--) kek();
            buys.pb(i, x);
            events[i] = x;
        }
    }

    stack<int> active; i = 0;
    for(i = j = 0; j < n;) {
        while(i < n and adds[i] < buys[j].first) active.push(adds[i++]);
        int k = j + 1;
        while(k < n and buys[k].first == buys[k-1].first + 1) k++;
        ans[active.top()] = buys[j].second; active.pop();
        for(++j; j < k; j++) {
            if(buys[j].second < buys[j-1].second) kek();
            ans[active.top()] = buys[j].second; active.pop();
        }
    }

    set<int> have;
    for(i = 0; i < 2*n; i++) {
        if(events[i]) {
            auto x  = *have.begin();
            have.erase(have.begin());
            if(x ^ events[i]) kek();
        } else {
            have.insert(ans[i]);
        }
    }

    cout << "YES" << '\n';
    for(auto x: ans) if(x) cout << x << ' ';
}