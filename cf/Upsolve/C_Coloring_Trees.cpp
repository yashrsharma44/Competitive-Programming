#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> cost(n, vector<int>(m + 1, 0));
    for (int i = 0; i < n; i++)
        for (int j = 1; j <= m; j++) cin >> cost[i][j];

    int MAX = 1e18;
    int SZ = 105;
    vector<vector<vector<int>>> cache(SZ, vector<vector<int>>(SZ, vector<int>(SZ, -1)));

    // dp(i, j, k) -> Min cost required to paint i trees, with last
    // color as k and having beauty as j.
    function<int(int, int, int)> dp = [&](int i, int beaut, int left) {
        // cout << i << " " << beaut << " " << left << endl;
        if (beaut > k) return MAX;
        // base case
        if (i == n) {
            // invariant:
            // i == n
            // beaut <= k
            if (beaut == k) return 0LL;
            return MAX;
        }

        if (cache[i][beaut][left + 1] != -1) return cache[i][beaut][left + 1];
        int ans = MAX;
        if (c[i] == 0) {
            for (int color = 1; color <= m; color++) {
                if (c[i] == 0) {
                    // need to add the cost
                    if (color == left) {
                        // no component increase
                        ans = min(ans, dp(i + 1, beaut, color) + cost[i][color]);
                    } else {
                        ans = min(ans, dp(i + 1, beaut + 1, color) + cost[i][color]);
                    }
                }
            }
        } else {
            // already colored, check if left_color is same
            if (left == c[i]) {
                // no component increase
                ans = min(ans, dp(i + 1, beaut, c[i]));
            } else {
                ans = min(ans, dp(i + 1, beaut + 1, c[i]));
            }
        }
        // cout << i << " " << beaut << " " << left << " " << ans << endl;

        return cache[i][beaut][left + 1] = ans;
    };

    int ans = dp(0, 0, -1);
    if (ans == MAX) ans = -1;
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