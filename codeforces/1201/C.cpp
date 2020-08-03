#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
constexpr int INF = 2e9 + 2;
constexpr int N = 2e5 + 5;
int a[N], n, k;

bool check(int x) {
    int64_t reqd = 0;
    for(int i = n/2; i < n; i++) 
        reqd += max(0, x-a[i]);
    return reqd <= k;
}

int binarySearch(int low, int high) {
    while(low <= high) {
        int mid = (1ll*low + high) / 2;
        if(check(mid))          // if true, the answer could be larger
            low = mid + 1;     
        else                    // if false, the answer has to be smaller
            high = mid - 1;    
    }                           // at the end of the loop (low > high)
    return high;                // high will point to the last true
}                               // low will point to the first false

int32_t main() {
    IOS;
    cin >> n >> k;
    for(int i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+n);           
    cout << binarySearch(1, INF);
    return 0;
}