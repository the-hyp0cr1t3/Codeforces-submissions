/**
 🍪 the_hyp0cr1t3
 🍪 10.01.2022 20:52:48
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

    int i, n;
    cin >> n;

    auto query = [](int c) {
        cout << "+ " << c << endl;
        cin >> c; return c;
    };

    int l = 1, r = n - 1;
    while(r > l) {
        int border = (r + n - 1) / n * n;
        int mid = l + r + 1 >> 1;
        int c = border - mid;
        auto x = query(c);
        if(x >= border / n)
            l = mid;
        else
            r = mid - 1;
        l += c, r += c;
    }

    cout << "! " << l << endl;

} // ~W