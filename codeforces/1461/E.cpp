/**
  the_hyp0cr1t3
  11.12.2020 21:05:29
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
using bigint = __int128;
// using bigint = uint64_t;
int N = 5e5+5;

void kek(bigint t) {
    cout << (t < 0? "Yes" : "No"); exit(0);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int64_t _k, _A, _B, _t, _x, _y;
    cin >> _k >> _A >> _B >> _t >> _y >> _x;
    bigint k, A, B, t, x, y, times, b, zero{0};
    k = _k; A = _A; B = _B;
    t = _t; x = _x; y = _y;
    b = max(A-1, B-x);

    if(x-y == zero) {
        if(k <= b) kek(-1);
        times = (max(zero, k-b) + y-1) / y;
        k -= times * y;
        t -= times;
        if(k < A) kek(t);
        kek(-1);
    }

    if(x-y < zero) {
        times = (max(zero, k-b) + y-1) / y;
        t -= times;
        k -= times * y;
        if(k < A) kek(t);
        t -= (k-A+1 + y-x-1) / (y-x);
        kek(t);
    }

    set<bigint> seen;
    while(N--) {
        times = (max(zero, b-k+1) + x-y-1) / (x-y);
        t -= times;
        k += times * (x-y);
        if(seen.count(k)) kek(-1);
        seen.insert(k);
        times = (max(zero, k-b) + y-1) / y;
        k -= times * y;
        t -= times;
        if(k < A) kek(t);
    } cout << "Yes";
} // ~W 