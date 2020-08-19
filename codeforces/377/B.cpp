/**
 🍪 the_hyp0cr1t3
 🍪 19.08.2020 11:29:26
**/
#ifdef W
#include "k_II.h"
#else
#include <bits/stdc++.h>
using namespace std;
#define aylmao cin.tie(nullptr)->sync_with_stdio(false);
#endif
// #define int long long
#define ff first
#define ss second
#define endl '\n'
#define pb emplace_back
#define sz(x) (int)((x).size())
#define all(x) x.begin(), x.end()
#define Luv(...) [&](auto&& u, auto&& v) { return __VA_ARGS__; }
auto chmax = [](auto& A, auto&& B) { return B > A? A = B, true : false; };
auto chmin = [](auto& A, auto&& B) { return B < A? A = B, true : false; };

using ll = long long;
using pii = pair<int, int>;
const ll DESPACITO = 2e18;
const int INF = 2e9, MOD = 1e9+7;
const int N = 2e5+5;

struct A {
    int id, val;
    A(int id = -1, int val = -1) : id(id), val(val) {}
    friend ostream& operator<<(ostream& os, const A& e) { os << e.id << ' ' << e.val; return os; }
};

struct B {
    int id, val, cost;
    B(int id = -1, int val = -1, int cost = -1) : id(id), val(val), cost(cost) {}
    friend ostream& operator<<(ostream& os, const B& e) { os << e.id << ' ' << e.val << ' ' << e.cost; return os; }
};

int32_t main() {
    aylmao
    int i, j, k, n, m; ll S;
    cin >> n >> m >> S;
    vector<A> a(m);
    vector<B> b(n);
    for(i = 0; i < m; i++) 
        cin >> a[i].val, a[i].id = i;
    for(i = 0; i < n; i++) 
        cin >> b[i].val, b[i].id = i;
    for(i = 0; i < n; i++) 
        cin >> b[i].cost;
    
    auto cmp1 = [](const auto& u, const auto& v) { return u.val > v.val; };
    auto cmp2 = [](const auto& u, const auto& v) { return u.cost > v.cost; };

    sort(all(a), cmp1);
    sort(all(b), cmp1);

    auto check = [&] (int x) {
        ll tot = 0;
        priority_queue<B, vector<B>, decltype(cmp2)>pq(cmp2);
        for(i = 0, j = 0; j < m; j+=x) {
            for(; i < n and b[i].val >= a[j].val; i++)
                pq.push(b[i]);
            if(pq.empty()) return false;
            tot += pq.top().cost;
            pq.pop();
        }
        return tot <= S;
    };
    
    auto binarySearch = [&] (int low, int high) {
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(mid))
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low; 
    };
    
    auto d = binarySearch(1, m);
    if(d == m+1) return cout << "NO", 0;

    vector<int> ans(m);
    priority_queue<B, vector<B>, decltype(cmp2)>pq(cmp2);
    for(i = 0, j = 0; j < m; j+=d) {
        for(; i < n and b[i].val >= a[j].val; i++)
            pq.push(b[i]);
        for(k = 0; k < d and j+k < m; k++) 
            ans[a[j+k].id] = pq.top().id+1;
        pq.pop();
    }

    cout << "YES" << endl;
    for(i = 0; i < m; i++) 
        cout << ans[i] << " \n"[i == m-1];
    return 0;
}