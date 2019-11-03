#include <bits/stdc++.h>
//#define long int64_t
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
    IOS;
    ll q, n, m, hcf;
    cin >> n >> m >> q;
    hcf = __gcd(n, m);
    while (q--) {
        ll ind1, ind2, a, b, a_hcf, b_hcf, A, B;
        cin >> ind1 >> a >> ind2 >> b;
        a_hcf = ind1 == 1? n/hcf : m/hcf;
        b_hcf = ind2 == 1? n/hcf : m/hcf;
        A = a/a_hcf - (a%a_hcf == 0);
        B = b/b_hcf - (b%b_hcf == 0);
        if (A == B)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
