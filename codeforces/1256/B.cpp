#include <bits/stdc++.h>
#define cerr if(0)cerr
#define watch(x) cerr << (#x) << " is " << (x) << endl
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
const int N = 100 + 5;

int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, i, j, a[N], k = 1, b[N], last = 1;
        cin >> n;
        for(i = 1; i <= n; i++) {
            cin >> a[i];
            b[i] = i;
        }
        for(i = 1; i <= n; i++) {
            if (a[i] == b[k]) {
                cout << a[i] << " ";
                b[a[i]] = 0;
                for(j = last; j < i-1; j++) {
                    if (b[a[j]])
                        cout << a[j] << " ";
                    b[a[j]] = 0;
                }
                if (i > 1) {
                    swap(a[i], a[i-1]);
                    last = i;
                    i -= 2; 
                }
                while(!b[k] and k <=n)
                    k++;
            }
        }
        cout << endl;
    }
    return 0;
}
