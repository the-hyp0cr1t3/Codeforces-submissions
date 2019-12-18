#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
using namespace std;
#define rev(a) reverse(a.begin(),a.end())
#define pb push_back

int32_t main() {
    IOS;
    int a, b;
    cin >> a >> b;
    vector<int> ans;
    auto check = [&] (auto& Self, int n) {
        if (n > b) return 0;
        if (n == b) return 1;
        if (Self(Self, 2*n)) 
            return ans.pb(2*n), 1;
        if (Self(Self, 10*n+1))
            return ans.pb(10*n+1), 1;
        return 0;
    };
    if (!check(check, a)) return cout << "NO", 0;
    cout << "YES" << endl;
    ans.pb(a);
    rev(ans);
    cout << ans.size() << endl;
    for (auto& x: ans) 
        cout << x << " ";
    return 0;
}