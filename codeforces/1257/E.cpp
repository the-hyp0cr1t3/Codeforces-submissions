#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define pb push_back
const int N = 2e5 + 5;
int a[N];
vector<int> lis;

bool check (int y, int search) {
    if (a[lis[y]] <= search)
        return 1;
    else
        return 0;
}

int binarySearch(int low, int high, int search) {
    while(low < high) {
        int mid = (low + high) / 2;
        if(check(mid, search))
            low = mid + 1;
        else
            high = mid;
    }
    return low; 
}

int32_t main() {
    IOS;
    int i, n, len = 0, k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    n = k1 + k2 + k3;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+k1);
    sort(a+k1, a+k1+k2);
    sort(a+k1+k2, a+n);
    for(i = 0; i < n; i++) {
        int x = binarySearch(0, len, a[i]);
        if (x == len)
            lis.pb(i), len++;
        else
            lis[x] = i;
    }
    cout << n - len << endl;
    return 0;
}