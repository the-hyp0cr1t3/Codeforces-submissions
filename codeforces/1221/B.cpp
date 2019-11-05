#include <bits/stdc++.h>
#define cerr if(0)cerr
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
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define ll long long

using namespace std;
const int N = 1e5 + 5;

int main() {
    IOS;
    int i, n;
    bool takenr = 0, takenc = 0;
    cin >> n;
    for(i = 0; i < n; i++) {
        takenc = takenr;
        for(int j = 0; j < n; j++) {
            if (takenc)
                cout << "B";
            else
                cout << "W";
            takenc^=1;
        }
        cout << endl;
        takenr^=1;
    }
    return 0;
}
