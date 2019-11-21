#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
#define min3(x,y,z) min(x,min(y,z))
#define DESPACITO 1000000000000000000 //1e18
#define min(a,b) (a<b?a:b)
template <typename T>
double dist(T x1, T y1, T x2, T y2) {
    return sqrt(1.0*(x1-x2)*(x1-x2)+1.0*(y1-y2)*(y1-y2));
}

int32_t main() {
    IOS;
    int i, n, ax, ay, bx, by, tx, ty, p, q;
    double total = 0, check, bin, mna, mnb, mnab, ans;
    mna = mnb = mnab = ans = DESPACITO;
    cin >> ax >> ay >> bx >> by >> tx >> ty >> n;
    for(i = 0; i < n; i++) {
        cin >> p >> q;
        bin = dist(p,q,tx,ty);
        total += 2*bin;
        mnab = min3(mna+dist(p,q,bx,by)-bin, mnb+dist(p,q,ax,ay)-bin, mnab);
        mna = min(dist(p,q,ax,ay)-bin, mna);
        mnb = min(dist(p,q,bx,by)-bin, mnb);
    }
    ans = total + min3(mnab, mna, mnb);
    cout << fixed << setprecision(8) << ans;
    return 0;
}