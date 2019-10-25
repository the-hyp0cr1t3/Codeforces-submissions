#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

int main() {
    int n, i, t[100005], counta = 0, countb = 0;
    cin >> n;
    int l = 0, r = n -1;
    for(i = 0; i < n; i++)
        cin >> t[i];
    int waita = 0, waitb = 0;
    while(l < r) {
        if (waita) {
            waita--;
            if (!waita) {
                l++;
                if (l==r) break;
                waita = t[l];
                counta++;
            }
        }
        else {
            if (l==r) break;
            waita = t[l];
            counta++;
        }
        if (waitb) {
            waitb--;
            if (!waitb) {
                r--;
                if (l==r) break;
                waitb = t[r];
                countb++;
            }
        }
        else {
            if (l==r) break;
            waitb = t[r];
            countb++;
        }
    }
    if (waita == waitb and !waita and l == r)
        counta++;
    cout << counta << " " << countb;
    return 0;
}
