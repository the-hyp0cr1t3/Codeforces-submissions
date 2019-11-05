#include <bits/stdc++.h>
//#define long int64_t
#define cerr if(1)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 1e5 + 5;

int main() {
    int i, n, ans = 0;
    cin >> n;
    ll sum = 0;
    while (sum < n) {
        sum += sum+1;
        ans++;
        if (n - sum < sum + 1 and n - sum > 0) {
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
}
