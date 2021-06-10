#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    int ans = 0;

    for (int y = 1; y <= n; y++) {
        int p = y + (a + c) - (b + d);
        int q = y + (a - d);

        int x = y + (c - b);

        if (p >= 1 && p <= n && q >= 1 && q <= n && x >= 1 && x <= n) {
            ans++;
        }
    }

    ans *= n;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}