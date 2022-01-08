/**
 🍪 the_hyp0cr1t3
 🍪 08.01.2022 17:30:44
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

int main() {
#if __cplusplus > 201703L
    namespace R = ranges;
#endif
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int i, t;
    cin >> t;

    auto f = [](int x) {
        return x * x + 2 * x + 3;
    };

    cout << f(f(f(t)+t)+f(f(t)));

} // ~W