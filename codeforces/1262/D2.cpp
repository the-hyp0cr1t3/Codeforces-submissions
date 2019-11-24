#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define T int
#define ordered_set tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define all(a) a.begin(),a.end()
#define s second
#define f first
#define ins insert
#define pb push_back
typedef pair<int, int> pii;
const int N = 2e5 + 5;
pii b[N]; 
int a[N];

bool Comparator (pii &x, pii &y) {
    if (x.f == y.f)
        return x.s < y.s;
    return x.f > y.f;
}

int32_t main() {
    IOS;
    int Q, n, i, j;
    cin >> n;
    for(i = 1; i <= n; i++) 
        cin >> a[i];
    for(i = 1; i <= n; i++) 
        b[i].f = a[i], b[i].s = i;
    sort(b+1, b+n+1, Comparator);
    //for(i = 1; i <= n; i++) 
    //    cout << "{" << b[i].f << ", " << b[i].s << "} ";
    //cout << endl;
    cin >> Q;
    vector<int> ans(Q+1);
    vector<pair<pii, int>> query;
    for (i = 1; i <= Q; i++) {
        int pos, k;
        cin >> k >> pos;
        query.pb({{k, pos}, i});
    }
    sort(all(query));
    //for (auto& x: query) 
    //    cout << "{{" << x.f.f << ", " << x.f.s << "}, " << x.s << "} ";
    //cout << endl;
    ordered_set p;
    for(i = 1, j = 0; i <= n; i++) {
        p.ins(b[i].s);
        while(j < Q and query[j].f.f == i)
            ans[query[j].s] = a[*p.find_by_order(query[j].f.s-1)], j++;
    }
    for(i = 1; i <= Q; i++) 
        cout << ans[i] << endl;
    return 0;
}