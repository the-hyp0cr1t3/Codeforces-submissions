#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define all(x) x.begin(), x.end()
using ll = long long;
constexpr int MOD = 1e9 + 7;

ll expo(ll A, ll B) {
    ll res{1}; while(B) {
        if(B & 1) res = res * A % MOD;
        B >>= 1; A = A * A % MOD;
    } return res;
}

int32_t main() {
    IOS;
    int i, n, m, k, j;
    cin >> n >> m >> k;
    
    vector<int> par(n), sz_(n, 1);
    iota(all(par), 0);
    
    auto getpar = [&] (int x) {
        int pp = x;
        while(par[pp] != pp)
            pp = par[pp];
        while(par[x] != x) {
            int z = par[x];
            par[x] = pp;
            x = z;
        }
        return pp;        
    };
    
    auto merge = [&] (int x, int y) {
        x = getpar(x);
        y = getpar(y);
        if (x == y) return false;
        if (sz_[x] < sz_[y]) swap(x, y);
        par[y] = x, sz_[x] += sz_[y];
        return true;
    };
    
    for(int z = 0; z+k <= n; z++)
        for(i = z, j = z+k-1; i < j; i++, j--) 
            merge(i, j);

    set<int> s;
    for(i = 0; i < n; i++) 
        s.insert(getpar(i));
    
    cout << expo(m, ll(s.size()));
    return 0;
}   