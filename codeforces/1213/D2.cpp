#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

const int INF = 2e9;
const int N = 2e5 + 5;
int a[N], frq[N], ops[N];

int32_t main() {
    IOS;
    int i, j, p, n, k, ans = INF;
    cin >> n >> k;
    for(i = 0; i < n; i++) 
        cin >> a[i];

    sort(a, a+n);
    
    for(i = 0; i < n; i++) {
        int op = 0;
        while(a[i] > 0) {
            frq[a[i]]++;        // how many elements can we bring down to this value
            ops[a[i]] += op;    // how many operations will it take to get these many elements
            if(frq[a[i]] == k)      // update answer if we have exactly k elements
                ans = min(ans, ops[a[i]]);      // trying to update answer with any set of elements
            a[i] /= 2;                          // other than the k smallest ones will not be optimal
            op++;
        }
    }
    
    cout << ans;
    return 0;
}