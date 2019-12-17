#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
#define pb push_back


const int N = 2e4 + 5;
int a[N];
int32_t main() {
    IOS;
    int i, n;
    cin >> n;
    vector<int> v, u;
    int sum = 0;
    for(i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i]%2 and a[i]<0) v.pb(i);
        if (a[i]%2 and a[i]>0) u.pb(i);
        a[i] /= 2;
        sum += a[i];
    }
    if (sum > 0) {
        for (auto& x: v) {
            if (!sum) break;
            a[x]--, sum--;
        }
    }
    else if (sum < 0) {
        for (auto& x: u) {
            if (!sum) break;
            a[x]++, sum++;
        }
    }
    for(i = 0; i < n; i++) 
        cout << a[i] << endl;
    return 0;
}