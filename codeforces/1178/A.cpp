#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define s second
#define f first
#define pb push_back
typedef pair<int, int> pii;
const int N = 100 + 5;
pii a[N];
vector<int> ans;
int32_t main() {
    IOS;
    int i, n, x, sum = 0, totsum = 0;
    cin >> n;
    cin >> x;
    sum = totsum = x;
    for(i = 0; i < n-1; i++) 
        cin >> a[i].f, a[i].s = i+2, totsum += a[i].f;
    sort(a, a+n-1);
    ans.pb(1);
    i = 0;
    while(2*a[i].f <= x and i < n-1)
        sum += a[i].f, ans.pb(a[i].s), i++;
    if (sum <= totsum/2)
        return cout << 0, 0;
    cout << i+1 << endl;
    for (auto& y: ans) 
        cout << y << " ";
    return 0;
}