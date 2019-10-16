#include <bits/stdc++.h>
using namespace std;
#define long int64_t

int main() {
    int n, i, a, sum = 0;
    cin >> n;
    multiset <pair<int,int>> s;
    for(i = 0; i < n; i++) {
        cin >> a;
        s.insert({a, i});
    }
    multiset <pair<int,int>> :: iterator itr; 
    for (itr = prev(s.end(), 1), i = 0;; --itr, i++){
        sum += 1 + i * itr->first;
        if  (itr == s.begin())
            break;
    }
    cout << sum << "\n";
    for (itr = prev(s.end(), 1), i = 0;; --itr, i++) {
        cout << 1 + itr->second << " ";
        if  (itr == s.begin())
            break;
    }
    return 0;
}
