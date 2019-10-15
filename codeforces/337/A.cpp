#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, m, i, k, min = 0;
    multiset<int> a;
    multiset <int> :: iterator itr1, itr2; 
    cin >> n >> m;
    for(i = 0; i<m; i++) {
        cin >> k;
        a.insert(k);
    }
    for(itr1 = a.begin(), itr2 = next(itr1, n-1); itr2 != a.end(); itr1++, itr2++) {
        if (itr1 == a.begin())
            min = *itr2 - *itr1;
        if (min > *itr2 - *itr1)
            min = *itr2 - *itr1;
    }
    cout << min;                
    return 0;
}
