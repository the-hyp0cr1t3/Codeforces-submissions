#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define endl "\n"
using namespace std;
const int N = 1e5 + 5;
int a[N];
void lose() {
    cout << "cslnb";
    exit(0);
}
void win() {
    cout << "sjfnb";
    exit(0);
}
int32_t main() {
    IOS;
    int i, n, same = 0, bad = 0;
    ll sum = 0;
    cin >> n;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    sort(a, a+n);
    for(i = 0; i < n; i++) {
        sum += a[i] - i;
        if (a[i] < i) lose();
        if (a[i] == a[i+1]) same++, bad += (i and a[i-1]+1 == a[i]);
    }
    if (!sum or same > 1 or bad or !(sum&1)) lose();
    win();
    return 0;
}