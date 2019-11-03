#include <bits/stdc++.h>
//#define long int64_t
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define MOD 1e8 + 7
#define INF 2e9
#define DESPACITO 1e18
#define PI acos(-1);
#define E 998244353
#define pb push_back
#define mp make_pair
#define ll long long

using namespace std;
const int N = 1e5 + 5;

deque <int> s{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

int add(int x) {
    if (s.size() < 1 or s[s.size()- 1] < x) {
        s.push_back(x);
        return 0;
    }
    auto it = s.begin();
    while(*it < x)
        it++;
    s.insert(it, x);
    return 0;
}

int main() {
    int i = 0, n;
    string str;
    cin >> n >> str;
    for (char c: str) {
        if (c == 'L')
            s.pop_front();
        else if (c == 'R')
            s.pop_back();
        else
            add(c-'0');
    }
    for (int x: s) {
        while (i < x)
            cout << 1, i++;
        cout << 0, i++;
    }
    for(; i < 10; i++)
        cout << 1;
    return 0;
}
