#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

int cache[2005][2005];

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    int MIN = -1e15;
    memset(cache, -1, sizeof(cache));
    function<int(int, int)> dp = [&](int i, int k) {
        if (k > i) return -1LL;
        if (i == 0 && k == 0) return 0LL;
        if (i == 0) return -1LL;

        if (cache[i][k] != -1) return cache[i][k];

        int ans = dp(i - 1, k);
        if (k >= 1 && dp(i - 1, k - 1) != -1 && dp(i - 1, k - 1) + a[i] >= 0) {
            ans = max(ans, dp(i - 1, k - 1) + a[i]);
        }

        if (ans < -1) return cache[i][k] = -1LL;
        return cache[i][k] = ans;
    };

    vector<vector<int>> ddp(n + 1, vector<int>(n + 1, -1));
    ddp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            ddp[i][j] = ddp[i - 1][j];
            if (j != 0 && ddp[i - 1][j - 1] != -1 && ddp[i - 1][j - 1] + a[i] >= 0) {
                ddp[i][j] = max(ddp[i][j], ddp[i - 1][j - 1] + a[i]);
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         assert(dp(i, j) == ddp[i][j]);
    //         cout << ddp[i][j] << " \n"[j == n];
    //     }
    // }
    // cout << endl;
    // cout << endl;

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= n; j++) {
    //         cout << dp(i, j) << " \n"[j == n];
    //     }
    // }

    for (int i = n; i >= 0; i--) {
        if (dp(n, i) >= 0) {
            cout << i << endl;
            return;
        }
    }
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