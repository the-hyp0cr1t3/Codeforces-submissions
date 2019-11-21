#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
using namespace std;
#define DESPACITO 1000000000000000000 //1e18
#define max(a,b) (a>b?a:b)
#define all(a) a.begin(),a.end()
#define pb push_back
vector<int> ans1, ans2;
int32_t main() {
    IOS;
    int i, n, b, l = 0, r = DESPACITO;
    cin >> n;
    cin >> b;
    r = b;
    ans1.pb(l), ans2.pb(r);
    for(i = 1; i < n/2; i++) {
        cin >> b;
        l = max(b-r, l);
        r = b-l;
        ans1.pb(l), ans2.pb(r);
    }
    for (auto& x: ans1)
        cout << x << " ";
    reverse(all(ans2));
    for (auto& x: ans2)  
        cout << x << " ";
    return 0;
}