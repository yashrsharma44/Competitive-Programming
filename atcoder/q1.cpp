#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, m, big, small;
    cin >> n >> m >> big >> small;
    int count = 0;
    vector<vector<int>> vis(n, vector<int>(m, 0));

    function<void(int, int, int, int)> dfs = [&](int i, int j, int a, int b) {
        if (i == n && a == 0 && b == 0) {
            count++;
            return;
        }

        if (i >= n) return;

        if (vis[i][j] != 0) {
            if (j + 1 < m) return dfs(i, j + 1, a, b);
            return dfs(i + 1, 0, a, b);
        }

        // put 1x1
        if (a > 0) {
            if (j + 1 < m) {
                vis[i][j] = 1;
                dfs(i, j + 1, a - 1, b);
                vis[i][j] = 0;
            } else {
                vis[i][j] = 1;
                dfs(i + 1, 0, a - 1, b);
                vis[i][j] = 0;
            }
        }

        // put 2x1 horizontally
        if (b > 0) {
            if (j + 1 < m && vis[i][j + 1] == 0) {
                vis[i][j] = 2;
                vis[i][j + 1] = 2;

                if (j + 2 < m)
                    dfs(i, j + 2, a, b - 1);
                else
                    dfs(i + 1, 0, a, b - 1);

                vis[i][j + 1] = 0;
                vis[i][j] = 0;
            }

            // put 2x1 vertically
            if (i + 1 < n && vis[i + 1][j] == 0) {
                vis[i][j] = 2;
                vis[i + 1][j] = 2;

                if (j + 1 < m)
                    dfs(i, j + 1, a, b - 1);
                else
                    dfs(i + 1, 0, a, b - 1);

                vis[i][j] = 0;
                vis[i + 1][j] = 0;
            }
        }
    };

    dfs(0, 0, small, big);

    cout << count << endl;
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
