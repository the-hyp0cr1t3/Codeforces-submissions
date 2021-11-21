/**
 🍪 the_hyp0cr1t3
 🍪 21.11.2021 14:32:14
**/
#ifdef Ws
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class key, class value = null_type, class cmp = std::less<key>>
using ordered_set = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
#define ook order_of_key    // count of elements strictly smaller than k
#define fbo find_by_order   // iterator to kth element starting from 0

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, n; int64_t ans = 0;
        cin >> n;
        ordered_set<pair<int, int>> os;
        while(n--) {
            int a; cin >> a;
            int l = os.ook({a, -1});
            int r = os.size() - os.ook({a, 1e9});
            ans += min(l, r);
            os.insert({a, n});
        }

        cout << ans << '\n';
    }();

} // ~W