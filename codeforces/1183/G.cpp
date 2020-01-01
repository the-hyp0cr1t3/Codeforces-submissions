#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define ll long long
using namespace std;
#define min(a,b) (a<b?a:b)
#define ff first
#define ss second
#define INF 2000000000 //2e9
using pii = pair<int, int>;

void solve () {
    int n, i, a, d;
    ll ans1 = 0, ans2 = 0;
    cin >> n;
    map <int,pii> cnt;
    for(i = 0; i < n; i++) {
        cin >> a >> d;
        cnt[a].ff++;
        if (d) cnt[a].ss++;
    }
    priority_queue <pii> pq;
    for (auto [k, v]: cnt) 
        pq.push(v);
    int cur = INF;
    while(!pq.empty() and cur) {
        pii t = pq.top();
        pq.pop();
        if (t.ff <= cur)
            ans1 += t.ff, ans2 += t.ss, cur = t.ff-1;
        else
            t.ff = cur, t.ss = min(cur, t.ss), pq.push(t);
    }
    cout << ans1 << " " << ans2 << endl;
}

int32_t main() {
    IOS;
    int Q;
    for(cin >> Q; Q; Q--)
        solve();
    return 0;
}