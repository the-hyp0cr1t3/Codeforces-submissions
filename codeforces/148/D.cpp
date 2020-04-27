#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;
const int N = 1000 + 5;
double cache[N][N][2];
double dp(int w, int b, int who) {
    if(w == 0)
        return 0.0;
    if(b < 0)
        return 0.0;
    double &ans = cache[w][b][who];
    if (ans != -1.0)
        return ans;
    
    if(who) {
        ans = w+b-1? 1.0*b/(w+b) : 0.0;
        if(w+b-1) ans *= 1.0*(b-1)/(w+b-1)*dp(w, b-2, 0) + 1.0*w/(w+b-1)*dp(w-1, b-1, 0);
    }
    else {
        ans = 1.0*w/(w+b);
        ans += 1.0*b/(w+b)*dp(w, b-1, 1);
    }
    return ans;
}

int32_t main() {
    IOS;
    int i, j, k, w, b;
    cin >> w >> b;
    for(i = 0; i <= w; i++) 
        for(j = 0; j <= b; j++) 
            for(k = 0; k < 2; k++) 
                cache[i][j][k] = -1.0;
    cout << fixed << setprecision(10) << dp(w, b, 0);
    return 0;
}