#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int n;
long S;
pair <long, long> a[100005];
long arr[100005];

pair <bool, long> check (int x) {
    long cost = 0;
    for(int i = 1; i <= n; i++)
        arr[i] = a[i].second + a[i].first * x;
    sort (arr+1, arr+n+1);
    for(int i = 1; i <= x ; i++)
        cost += arr[i];
    return {(cost <= S), cost};
}

pair <int, long> binarySearch(int low, int high) {
    while(low <= high) {
        int mid = (low + high) / 2;
        if(check(mid).first)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return {high, check(high).second};
}


int main() {
    long i, val;
    cin >> n >> S;
    for(i = 1; i <= n; i++) {
        cin >> val;
        a[i] = {i, val};
    }
    pair <int, long> p;
    p = binarySearch(1, n);
    cout << p.first << " " << p.second;
    return 0;
}
