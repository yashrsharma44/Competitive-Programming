#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int four;
    cin >> four;
    int n = pow(four, 0.5);
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> grid[i][j];
        }
    }
    if (n == 1) {
        cout << grid[1][1] << endl;
        return;
    }
    function<int(int, int, int, int)> recur = [&](int r1, int c1, int r2, int c2) {
        int m = -1;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                m = max(m, grid[i][j]);
            }
        }
        // cout << r1 << " " << r2 << " " << c1 << " " << c2 << endl;
        if (r1 + 1 != r2 && c1 + 1 != c2) {
            int mr = (r1 + r2) >> 1;
            int mc = (c1 + c2) >> 1;

            return m + recur(r1, c1, mr, mc) + recur(r1, mc + 1, mr, c2) + recur(mr + 1, c1, r2, mc) + recur(mr + 1, mc + 1, r2, c2);
        }
        return m + grid[r1][c1] + grid[r2][c2] + grid[r1][c2] + grid[r2][c1];
    };

    int ans = recur(1, 1, n, n);
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