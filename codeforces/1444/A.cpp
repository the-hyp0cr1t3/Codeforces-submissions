/**
 🍪 the_hyp0cr1t3
 🍪 01.11.2020 16:36:37
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
#include <ext/pb_ds/assoc_container.hpp>
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

template<typename T>
T expo(T A, int64_t B) {
    T res{1}; while(B) {
        if(B & 1) res = res * A;
        B >>= 1; A = A * A;
    } return res;
}

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int the_real_main() {
    int64_t P, Q, p, q; int i;
    cin >> P >> Q; p = P, q = Q;
    __gnu_pbds::gp_hash_table<int64_t, int64_t, custom_hash> pfP, pfQ;
    for(i = 2; i*i <= q; i++) {
        if(q % i) continue;
        while(q % i == 0)
            pfQ[i]++, q /= i;
        while(p % i == 0)
            pfP[i]++, p /= i;
    }
    if(q > 1) {
        pfQ[q]++;
        while(p % q == 0)
            pfP[q]++, p /= q;
    }

    int64_t ans = 1;
    for(auto [prime, cnt]: pfQ)
        chmax(ans, P / expo(prime, max(0ll, pfP[prime] - cnt + 1)));
    cout << ans << '\n';
    return 0;
}

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) the_real_main();
}