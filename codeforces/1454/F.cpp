/**
 🍪 the_hyp0cr1t3
 🍪 24.11.2020 20:16:31
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

int ocoiek() {
    int i, j, n, m = 0;
    cin >> n;
    vector<int> a(n);
    map<int, int> compress;
    for(auto& x: a) cin >> x, compress[x];
    for(auto& [k, v]: compress)
        v = m++;
    vector<vector<int>> pos(m);
    for(i = 0; i < n; i++) {
        a[i] = compress[a[i]];
        pos[a[i]].pb(i);
    }

    vector<int> par(n+1, -1), active(n);
    auto get_par = [&](int A) {
        while(par[A] >= 0) {
            if(par[par[A]] >= 0) par[A] = par[par[A]];
            A = par[A];
        } return A;
    }; auto SZ = [&](int x) { return -par[x]; };
    
    auto merge = [&](int A, int B) {
        A = get_par(A); B = get_par(B);
        if(A == B) return false;
        if(-par[A] < -par[B]) swap(A, B);
        par[A] += par[B]; par[B] = A;
        return true;
    };

    int cnt = 0, L = n+1, R = -2;
    auto push = [&](int idx) {
        if(active[idx]) return;
        if(idx-1 >= 0 and active[idx-1])
            merge(idx, idx-1);
        if(idx+1 < n and active[idx+1])
            merge(idx, idx+1);
        active[idx] = true; cnt++;
        L = min(L, idx);
        R = max(R, idx);
    };

    for(i = m-1; ~i; --i) {
        int inseg = 0;
        for(j = 1; j < sz(pos[i])-1; j++)
            if(L-1 <= pos[i][j] and pos[i][j] <= R+1)
                push(pos[i][j]), inseg++;
        if(sz(pos[i]) > 2) {
            if(!cnt) push(pos[i][1]), inseg++;
            if(SZ(get_par(L)) == cnt and inseg) {
                cout << "YES" << '\n';
                cout << L << ' ' << cnt << ' ' << n-1 - R << '\n';
                return 0;                
            }
        }
        for(auto p: pos[i]) push(p);
    }

    cout << "NO" << '\n';
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int Q; for(cin >> Q; Q; Q--) ocoiek();
} // ~W