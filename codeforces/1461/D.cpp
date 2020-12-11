/**
 🍪 the_hyp0cr1t3
 🍪 11.12.2020 20:52:32
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

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, n, Q;
    cin >> n >> Q;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    set<int64_t> good;
    
    Y([&](auto self, int l, int r) -> void {
        sort(a.begin()+l, a.begin()+r+1);
        good.insert(accumulate(a.begin()+l, a.begin()+r+1, 0ll));
        if(a[l] == a[r]) return;
        int m;
        for(m = l; m <= r; m++) if(a[m] > (a[l] + a[r] >> 1)) break;
        self(l, m-1); self(m, r);
    })(0, n-1);

    while(Q--) {
        int64_t x; cin >> x;
        cout << (good.count(x)? "Yes" : "No") << '\n';
    }

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W 