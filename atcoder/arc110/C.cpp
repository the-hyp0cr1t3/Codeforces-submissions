/**
 🍪 the_hyp0cr1t3
 🍪 05.12.2020 18:07:22
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
int a[N];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int i, j, n;
    cin >> n;
    for(i = 0; i < n; i++)
        cin >> a[i], --a[i];

    vector<int> seg(2*n);

    auto update = [&](int pos, int val = 1) {
        for(seg[pos += n] = val; pos >>= 1;)
            seg[pos] = seg[pos<<1] + seg[pos<<1|1];
    };

    auto query = [&](int l, int r) {
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l&1) res += seg[l++];
            if(r&1) res += seg[--r];
        } return res;
    };

    int64_t inversions = 0;
    for(i = 0; i < n; i++) {
        inversions += query(a[i], n);
        update(a[i]);
    }

    if(inversions ^ n-1) return cout << -1, 0;

    for(i = 1; i < n; i++) {
        j = i;
        while(j and a[j] < a[j-1]) {
            swap(a[j], a[j-1]);
            cout << j << '\n'; --j;
        } if(j < i) --i;
    }
} // ~W 