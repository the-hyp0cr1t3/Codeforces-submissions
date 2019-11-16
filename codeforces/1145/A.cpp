#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define max(a,b) (a>b?a:b)
const int N = 17;
int n, a[N];

int thanossort (int l, int r) {
    int i; bool flag = 0;
    for(i = l+1; i < r; i++) {
        if (a[i] < a[i-1]) {
            flag = 1;
            break;
        }
    }
    if (!flag) return r-l;
    else
        return (max(thanossort (l, (l+r)/2), thanossort ((l+r)/2, r)));
}

int32_t main() {
    IOS;
    int i;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    cout << thanossort(0, n);
    return 0;
}