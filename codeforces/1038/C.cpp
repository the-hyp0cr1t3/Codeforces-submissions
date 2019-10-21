#include <bits/stdc++.h>
using namespace std;
#define long int64_t

bool doBothPlayersStillExist (pair<int, char> x) {
    return (x.second == 'a' || x.second == 'b');
}

int main() {
    int n, i = 1, x;
    pair<long, long> score = {0, 0};
    cin >> n;
    multimap <int, char> m;
    for(i = 0; i < 2 * n; i++) {
        cin >> x;
        m.insert({x, i < n ? 'a' : 'b'});
    }
    while (find_if(m.begin(), m.end(), doBothPlayersStillExist) != m.end()) {
        if ((i & 1) && m.begin()->second == 'a')
            score.first += m.begin()->first;
        if (!(i & 1) && m.begin()->second == 'b')
            score.second += m.begin()->first;
        m.erase(m.begin());
        i++;
    }

    cout << score.first - score.second;
    return 0;
}
