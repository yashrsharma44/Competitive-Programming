#include <bits/stdc++.h>
// #define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> cost(m + 1, vector<int>(2, 0));
    for (int c = 0; c < m; c++) {
        int dot = 0, has = 0;
        for (int r = 0; r < n; r++) {
            if (grid[r][c] == '.') dot += 1;
            if (grid[r][c] == '#') has += 1;
        }
        cost[c + 1][0] = cost[c][0] + n - dot;
        cost[c + 1][1] = cost[c][1] + n - has;
    }

    vector<vector<int>> cache(1005, vector<int>(2, -1));

    function<int(int, int)> dp = [&](int col, int color) {
        if (col < 0) return INT_MAX;
        if (col == 0) return 0;

        if (cache[col][color] != -1) return cache[col][color];

        int ans = INT_MAX;
        for (int z = x; z <= y; z++) {
            int cst = cost[col][color];
            if (col - z >= 0) {
                cst -= cost[col - z][color];
            }

            int DP = dp(col - z, 1 - color);
            if (DP == INT_MAX) continue;
            ans = min(ans, cst + DP);
        }
        // if (color == 1)
        //     cout << col << " " << color << " " << ans << endl;
        return cache[col][color] = ans;
    };

    int ans = min(dp(m, 0), dp(m, 1));
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}