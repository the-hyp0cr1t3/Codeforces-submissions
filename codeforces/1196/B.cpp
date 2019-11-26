#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
using namespace std;
const int N = 2e5 + 5;
int a[N], odd[N];
int32_t main() {
    IOS;
    int Q;
    cin >> Q;
    odd[0] = 0;
    while (Q--) {
        int n, i, k;
        bool bad = 0;
        cin >> n >> k;
        for(i = 1; i <= n; i++) 
            cin >> a[i], odd[i] = odd[i-1] + (a[i]&1);
            
        for(i = n-k+1; i <= n; i++)
            if (odd[i]-odd[i-n+k-1] <= 0) bad = 1;

        if (odd[n] < k)
            bad = 1;

        if ((odd[n]-k+1)%2==0)
            bad = 1;

        if (bad) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for(i = 1; i <= n and k-1; i++) 
            if (odd[i]>odd[i-1])
                cout << i << " ", k--;
        cout << n << endl;
    }
    return 0;
}