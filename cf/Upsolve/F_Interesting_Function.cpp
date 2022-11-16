#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;
int poww(int b, int e) {
    if (e == 0) return 1LL;
    int ans = e % 2 == 1 ? b : 1LL;
    int res = poww(b, e >> 1);
    return res * res * ans;
}
void solve() {
    int l, r;
    cin >> l >> r;

    auto cal = [&](int m) {
        int count = 0;
        int i = 0;
        while (m / poww(10, i) > 0) {
            count += m / poww(10, i);
            i++;
        }
        return count;
    };

    // cout << poww(10, 0) << " " << poww(10, 1) << " " << poww(10, 2) << endl;

    int ans = cal(r) - cal(l);
    cout << ans << endl;
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