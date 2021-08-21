/**
 🍪 the_hyp0cr1t3
 🍪 21.08.2021 18:16:20
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

const int64_t k_II = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);
    int i, j, n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(auto& [x, y]: a)
        cin >> x >> y;
    sort(all(a));

    auto check = [&](int d) {
        priority_queue<array<int, 2>> mx;
        priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> mn;

        for(i = 0; i < n; i++) {
            mx.push({a[i][1], i});
            mn.push({a[i][1], i});
        }

        for(i = j = 0; i < n; i++) {
            while(j < n and a[j][0] - a[i][0] < d) j++;
            while(!mx.empty() and mx.top()[1] < j) mx.pop();
            while(!mn.empty() and mn.top()[1] < j) mn.pop();
            if(mx.empty() or mn.empty()) break;
            if(abs(a[i][1] - mx.top()[0]) >= d or abs(a[i][1] - mn.top()[0]) >= d)
                return true;
        }
        return false;
    };

    int lo = 0, hi = 1e9;
    while(lo <= hi) {
        int mid = lo + hi >> 1;
        if(check(mid)) lo = mid + 1;
        else hi = mid - 1;
    }

    cout << hi << '\n';
} // ~W