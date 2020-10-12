/**
 🍪 the_hyp0cr1t3
 🍪 12.10.2020 15:09:31
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
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e14;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

struct Wave {
    int l{0}, r{0}; int64_t mons{0}; bool ok{true};
    Wave() = default;
    Wave(int l, int r, int64_t mons): l(l), r(r), mons(mons) {}
};

int32_t main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; int64_t k;
    cin >> n >> k;
    vector<Wave> waves(n);
    for(int i = 0; i < n; i++)
        cin >> waves[i].l >> waves[i].r >> waves[i].mons;

    vector<int64_t> cache(n, -1);
    int64_t ans = Y([&](auto dp, int idx) -> int64_t {
        auto& ans = cache[idx];
        if(~ans) return ans;
        ans = DESPACITO;
        int64_t used = 0, have = k;
        for(int i = idx; i < n; i++) {
            used += waves[i].mons;
            if((waves[i].mons - have) > k * (waves[i].r - waves[i].l))
                break;
            int64_t newhave = have;
            if(waves[i].mons <= have) newhave -= waves[i].mons;
            else newhave = (waves[i].mons - have + k-1) / k * k - (waves[i].mons - have);
            if(i+1 == n) chmin(ans, used);
            else if((waves[i].mons - have + k-1) / k < waves[i].r - waves[i].l
                or waves[i+1].l > waves[i].r)
                    chmin(ans, used + newhave + dp(i+1));
            have = newhave;
        } return ans;
    })(0);

    cout << (ans == DESPACITO? -1 : ans) << '\n';
}