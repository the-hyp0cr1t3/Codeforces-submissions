#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define INF 2000000000 //2e9

int32_t main() {
    IOS;
    int i, n, a, sum = 0, smolodd = INF, bigboiodd = -INF;
    cin >> n;
    for(i = 0; i < n; i++) {
        cin >> a;
        if (a > 0) {
            sum += a;
            if (a & 1 and a < smolodd)
                smolodd = a;
        }
        else {
            if (((a&1)+2)&1 and a > bigboiodd)
                bigboiodd = a;
        }
    }
    if (sum & 1)
        return cout << sum, 0;
    if (sum == smolodd)
        return cout << sum + bigboiodd, 0;
    return cout << max(sum - smolodd, sum + bigboiodd), 0;
}