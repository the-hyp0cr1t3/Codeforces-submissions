/**
 🍪 the_hyp0cr1t3
 🍪 14.10.2021 19:47:16
**/
#ifdef W
    #include <k_II.h>
#else
    #include <bits/stdc++.h>
    using namespace std;
#endif

template<class T> class Y {
    T f;
public:
    template<class U> explicit Y(U&& f): f(forward<U>(f)) {}
    template<class... Args> decltype(auto) operator()(Args&&... args) {
        return f(ref(*this), forward<Args>(args)...);
    }
}; template<class T> Y(T) -> Y<T>;

int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr);

    int tests; cin >> tests;
    while(tests--) []() {
        int i, j, ans = 100;
        string s; cin >> s;
        for(int p = 0; p < 64; p++) {
            int res = 0;
            string t = to_string(1LL << p);
            for(i = 0, j = 0; i < s.size(); i++) {
                if(j < t.size() and s[i] == t[j])
                    j++;
                else
                    res++;
            }
            res += t.size() - j;
            ans = min(ans, res);
        }

        cout << ans << '\n';

    }();

} // ~W