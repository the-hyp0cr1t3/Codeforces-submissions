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
    int ans = 2, x1, x2, x3;
    char p1, p2, p3;
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    x1 = s1[0];
    x2 = s2[0];
    x3 = s3[0];
    p1 = s1[1];
    p2 = s2[1];
    p3 = s3[1];
    if (s1 == s2 or s2 == s3 or s1 == s3)
        ans = 1;
    if (s1 == s2 and s2 == s3)
        ans = 0;
    if (p1 == p2 and (abs(x1 -x2) == 1 or abs(x1 -x2) == 2) or p2 == p3 and (abs(x3 -x2) == 1 or abs(x3 -x2) == 2) or p1 == p3 and (abs(x1 -x3) == 1 or abs(x1 -x3) == 2))
            ans = 1;
    if (p1 == p2 and p2 == p3)
        if (x1-x2 == x2-x3 and (x1-x2 == 1 or x1-x2 == -1) or x2-x3 == x3-x1 and (x2-x3 == 1 or x2-x3 == -1) or x3 - x1 == x1-x2 and (x3-x1 == 1 or x3-x1 == -1) )
            ans = 0;
    cout << ans;
    return 0;
}
