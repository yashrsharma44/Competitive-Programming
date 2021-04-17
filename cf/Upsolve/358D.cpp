#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

int cache[3005][3];

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];
    for (int i = 1; i <= n; i++) cin >> c[i];

    memset(cache, -1, sizeof cache);

    function<int(int, int)> dp = [&](int i, int state) {
        if (i == n) {
            if (state == 1) return b[i];
            return a[i];
        }
        if (cache[i][state] != -1) return cache[i][state];
        if (state == 0) {
            return cache[i][state] = max(dp(i + 1, 1) + a[i], dp(i + 1, 0) + b[i]);
        }

        return cache[i][state] = max(dp(i + 1, 1) + b[i], dp(i + 1, 0) + c[i]);
    };

    int ans = dp(1, 0);
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