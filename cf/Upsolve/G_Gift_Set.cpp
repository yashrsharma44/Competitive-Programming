#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (a < b) swap(a, b);

    if (a == b) {
        cout << (min(x, y) / a) << endl;
        return;
    }

    auto check = [&](int m) {
        int k1 = floorl((x - (m * b)) * 1.0l / (a - b));
        int k2 = ceill(((m * a) - y) * 1.0l / (a - b));

        if (max(k2, 0LL) <= min(k1, m)) return true;
        return false;
    };

    int l = 0, r = 1e9 + 100;
    // last True
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (check(m))
            l = m;
        else
            r = m;
    }

    cout << l << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}