#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 1e5 + 5;

int d;
bool Comparator (pair <int, int> x, pair <int, int> y) {
    return x.first < y.first;
}

bool Comparator1 (pair <int, int> x, pair <int, int> y) {
    return (y.first - x.first < d);
}


pair <int, int> a[N];
int main() {
    int n, i, j;
    long f = 0, ans = 0;
    cin >> n >> d;
    for(i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    sort (a, a+n, Comparator);
    for(i = j = 0; i < n; i++) {
        while (Comparator1(a[i], a[j]) and j < n) {
            f += a[j++].second;
        }
        ans = max(ans, f);
        f -= a[i].second;
    }
    cout << ans;
    return 0;
}
