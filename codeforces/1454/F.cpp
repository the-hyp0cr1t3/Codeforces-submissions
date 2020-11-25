/**
 🍪 the_hyp0cr1t3
 🍪 25.11.2020 11:10:17
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

template<typename K, typename V, typename Hash = custom_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template<class T, class F>
struct Sparse {
    int N, K; F cmp;
    vector<vector<T>> table; vector<vector<int>> idx;
    template<class Iter, class Func> 
    explicit Sparse(Iter beg, Iter end, Func&& f)
        : N(end-beg), K(this->lg(N)), cmp(forward<Func>(f)),
            table(K+1, vector<T>(N)), idx(K+1, vector<int>(N)) {
        for(int i = 0; i < N; i++) {
            table[0][i] = *(beg+i);
            idx[0][i] = i;
        }
        for(int k = 1; k <= K; k++) {
            for(int i = 0; i+(1<<k) <= N; i++) {
                if(cmp(table[k-1][i], table[k-1][i+(1<<(k-1))])) {
                    table[k][i] = table[k-1][i];
                    idx[k][i] = idx[k-1][i];
                }
                else {
                    table[k][i] = table[k-1][i+(1<<(k-1))];
                    idx[k][i] = idx[k-1][i+(1<<(k-1))];
                }
            }
        }
    }

    int lg(int x) const {
        return 31 - __builtin_clz(x);
    }

    int query(int l, int r) const {
        int k = lg(r-l+1);
        r = r-(1<<k)+1;
        return cmp(table[k][l], table[k][r])? idx[k][l] : idx[k][r];
    }
};

template<class T, class F>
Sparse(T, T, F) -> Sparse<typename iterator_traits<T>::value_type, F>;

const int64_t DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5 + 5;

int ocoiek() {
    int i, n;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) cin >> x;
    Sparse Min(all(a), less{});
    Sparse Max(all(a), greater{});
    hash_map<int, int> fst, lst;
    for(i = 0; i < n; i++) {
        if(fst.find(a[i]) == fst.end()) fst[a[i]] = i;
        lst[a[i]] = i;
    }

    auto get = [&](const auto& st, int l, int r) {
        return a[st.query(l, r)];
    };

    for(i = 0; i < n; i++) {
        if(fst[a[i]] == i or i == lst[a[i]]) continue;
        int lo = fst[a[i]]+1, hi = i;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(get(Min, mid, i) == a[i]) hi = mid - 1;
            else lo = mid + 1;
        } int l = lo;
        lo = i, hi = lst[a[i]]-1;
        while(lo <= hi) {
            int mid = lo + hi >> 1;
            if(get(Min, i, mid) == a[i]) lo = mid + 1;
            else hi = mid - 1;
        } int r = hi;

        if(get(Max, 0, l-1) == a[i] and get(Max, r+1, n-1) == a[i]) {
            cout << "YES" << '\n';
            cout << l << ' ' << r-l+1 << ' ' << n-1-r << '\n';
            return 0;
        }
    } cout << "NO" << '\n';

    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W