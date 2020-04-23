#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
#define sz(Xx) (int)(Xx).size()
const int DESPACITO = 1000000000000000000;  //1e18

auto Try = [] (const vector<int>& a, int k) {
    int res = 0;
    for(int i = 0; i < sz(a)-1; i++)
        res += min(a[i]%k, k-(a[i]%k));
    return res;
};

int32_t main() {
    IOS;
    int i, n, sum = 0, ans = DESPACITO;
    cin >> n;
    vector<int> a(n);
    for(auto& x: a) 
        cin >> x;
    for(i = 1; i < n; i++) 
        a[i] += a[i-1];
    sum = a.back();
    for(i = 2; i*i <= sum and sum > 1; i++) {
        if(sum % i) continue;
        ans = min(ans, Try(a, i));
        while(sum % i == 0)
            sum /= i;
    }
    if(sum > 1) ans = min(ans, Try(a, sum));
    cout << (ans == DESPACITO? -1 : ans);
    return 0;
}