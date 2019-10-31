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
    int q;
    cin >> q;
    while (q--) {
        int n, i, r, a[N], disp = 0;
        cin >> n >> r;
        for(i = 0; i < n; i++)
            cin >> a[i];
        sort(a, a+n);
        for(i = 1; i < n; i++) {
            if (a[i] == a[i-1])
                a[i-1] = -1;
        }
        
        for(i = n-1; i >= 0; i--) {
            while (a[i] == -1) i--;
            if(a[i] - disp <= 0) break; 
            disp += r;
        }
        cout << disp/r << endl;
    }
    return 0;
}