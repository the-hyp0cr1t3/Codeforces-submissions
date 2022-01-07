/**
 🍪 the_hyp0cr1t3
 🍪 07.01.2022 19:33:35
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
    const int M = 30;

    int i; int64_t n, T; string s;
    cin >> n >> T >> s;
    R::reverse(s);
    for(auto& c: s) c -= 'a';

    array<int, M> cnt{};
    T -= (1LL << s[0]) - (1LL << s[1]);
    for(i = 2; i < n; i++) {
        T += 1LL << s[i];
        cnt[++s[i]]++;
    }

    if(T < 0) return cout << "nO" << '\n', 0;

    for(i = M - 1; ~i; i--)
        while(cnt[i]-- and 1LL << i <= T)
            T -= (1LL << i);

    cout << (T? "nO" : "yEs") << '\n';
} // ~W