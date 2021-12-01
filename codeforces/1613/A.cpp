/**
 🍪 the_hyp0cr1t3
 🍪 01.12.2021 20:05:40
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace r = ranges; namespace v = views;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        string a, b; int c, d;
        cin >> a >> c >> b >> d;
        if(a.size() + c == b.size() + d) {
            while(a.size() < b.size())
                a += '0';
            while(a.size() > b.size())
                b += '0';
            cout << (a == b? '=' : a < b? '<' : '>') << '\n';
        } else {
            cout << (a.size() + c > b.size() + d? '>' : '<') << '\n';
        }

    }();

} // ~W