/**
 🍪 the_hyp0cr1t3
 🍪 17.09.2020 01:34:15
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
#define pb emplace_back
#define sz(x) int(x.size())
#define all(x) x.begin(), x.end()
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class value = null_type, class cmp = std::less<key>>
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key    // count of elements strictly smaller than k
#define fbo find_by_order   // iterator to kth element starting from 0

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;
int a[N];

int32_t main() {
    aylmao
    int i, n, m;
    cin >> n >> m;
    for(i = 0; i < n; i++)
        cin >> a[i];

    auto get = [&](int x) {
        ordered_set<pair<int, int>> os;
        os.insert({0, INF}); int sum = 0; int64_t ans = 0;
        for(i = 0; i < n; i++) {
            sum += a[i] < x? -1 : 1;
            ans += os.ook({sum, -i});
            os.insert({sum, -i});
        } return ans;
    };

    cout << get(m) - get(m+1) << '\n';
}