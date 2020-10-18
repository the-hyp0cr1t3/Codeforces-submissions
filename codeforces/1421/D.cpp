/**
 🍪 the_hyp0cr1t3
 🍪 18.10.2020 15:08:19
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
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int the_real_main() {
    int i; int64_t dx, dy, ans = DESPACITO;
    cin >> dx >> dy;
    array<int64_t, 6> cost;
    for(i = 0; i < 6; i++)
        cin >> cost[i];

    // dx +ve, dy -ve
    auto check1 = [&](int64_t cnt) {
        int64_t costx = cnt * cost[0] + (dx - cnt) * cost[5];
        int64_t costy = (-dy + cnt) * cost[4];
        return costx + costy;
    };

    auto check1o = [&](int64_t cnt) {
        int64_t costy = cnt * cost[3] + (-dy - cnt) * cost[4];
        int64_t costx = (dx + cnt) * cost[5];
        return costx + costy;
    };

    // dx -ve, dy +ve
    auto check2 = [&](int64_t cnt) {
        int64_t costy = cnt * cost[0] + (dy - cnt) * cost[1];
        int64_t costx = (-dx + cnt) * cost[2];
        return costx + costy;
    };

    auto check2o = [&](int64_t cnt) {
        int64_t costx = cnt * cost[3] + (-dx - cnt) * cost[2];
        int64_t costy = (dy + cnt) * cost[1];
        return costx + costy;
    };

    // dx +ve, dy +ve
    auto check3 = [&](int64_t cnt) {
        int64_t common = cnt * cost[0];
        int64_t costx = max(dx - cnt, 0ll) * cost[5] + max(cnt - dx, 0ll) * cost[2];
        int64_t costy = max(dy - cnt, 0ll) * cost[1] + max(cnt - dy, 0ll) * cost[4];
        return costx + costy + common;
    };

    // dx -ve, dy -ve
    auto check4 = [&](int64_t cnt) {
        int64_t common = cnt * cost[3];
        int64_t costx = max(-dx - cnt, 0ll) * cost[2] + max(cnt + dx, 0ll) * cost[5];
        int64_t costy = max(-dy - cnt, 0ll) * cost[4] + max(cnt + dy, 0ll) * cost[1];
        return costx + costy + common;
    };

    auto tern = [&](int lo, int hi, auto check) {
        while(hi - lo > 4) {
            int mid = lo + hi >> 1;
            if(check(mid) >= check(mid+1)) lo = mid;
            else hi = mid + 1;
        }
        int64_t res = DESPACITO;
        for(int z = lo; z <= hi; z++)
            chmin(res, check(z));
        return res;
    };

    if(dx >= 0 and dy <= 0) {
    // dx +ve, dy -ve
        ans = min(tern(0, dx, check1), tern(0, -dy, check1o));
    } else if(dx <= 0 and dy >= 0) {
    // dx -ve, dy +ve
        ans = min(tern(0, dy, check2), tern(0, -dx, check2o));
    } else if(dx >= 0 and dy >= 0) {
        ans = tern(0, max(dx, dy), check3);
    } else {   
        ans = tern(0, max(-dx, -dy), check4);
    }

    cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}