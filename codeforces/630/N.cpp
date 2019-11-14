#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    double a, b, c, x, y;
    cin >> a >> b >> c;
    x = (-b + sqrt(b*b-4*a*c))/(2*a);
    y = (-b - sqrt(b*b-4*a*c))/(2*a);
    return cout << fixed << setprecision(6) << max(x, y) << endl << min(x, y), 0;
}