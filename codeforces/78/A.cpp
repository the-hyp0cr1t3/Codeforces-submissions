// Author: HarshKumar

#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll N = 1e6 + 6, M = 1e9 + 7;
bool isVowel(char c)
{
    set<ll> s = {'a', 'e', 'i', 'o', 'u'};
    return s.find(c) != s.end();
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);
    string a, b, c;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    ll x = 0, y = 0, z = 0;
    for (char c : a)
        x += isVowel(c);
    for (char c : b)
        y += isVowel(c);
    for (char c : c)
        z += isVowel(c);
    cout << (x == 5 && y == 7 && z == 5 ? "YES" : "NO") << '\n';
}