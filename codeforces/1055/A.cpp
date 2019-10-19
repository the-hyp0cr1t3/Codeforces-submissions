#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int func() {
    int n, i,j, s, a[1000005], b[1000005], pos = 0;
    bool ans;
    cin >> n >> s;
    s--;
    for(i = 0; i < n; i++) 
        cin >> a[i];
    for(i = 0; i < n; i++)
        cin >> b[i];

    if (!a[0]) return 0;
    
    while (pos < s) {
        pos ++;
        if (pos > n) return 0;
        while(!a[pos] || (pos == s? 0 : !b[pos])) {
            if (pos >= n) return 0;
            pos++;
        }
    }

    if (pos == s) return 1;
    
    while (pos > s) {
        pos--;
        if (pos <= 0) return 0;
        while(!b[pos]) {
            if (pos < 0) return 0;
            pos--;
        }
    }

    if (pos == s) return 1;
    else return 0;
}

int main() {
    func()? (cout << "YES") : (cout <<"NO");
    return 0;
}
