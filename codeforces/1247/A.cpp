#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
const int N = 1e5 + 5;

int main() {
    int a, b, i;
    cin >> a >> b;
    if (b == 1 and a == 9)
        cout << "9 10";
    else if (b-a == 1)
        cout << a << " " << b;
    else if (b == a)
        cout << 10*a + 1 << " " << 10*b + 2;
    else
        cout << -1;
    return 0;
}
    