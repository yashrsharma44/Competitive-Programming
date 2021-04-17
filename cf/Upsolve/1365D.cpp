#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

char grid[55][55];

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<int>> good;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'B') {
                for (int z = 0; z < 4; z++) {
                    int r = i + dr[z];
                    int c = j + dc[z];

                    if (r >= 0 && r < n && c >= 0 && c < m) {
                        if (grid[r][c] == 'G') {
                            // if neighbour has a good, not possible
                            cout << "No" << endl;
                            return;
                        }
                        if (grid[r][c] == '.') grid[r][c] = '#';
                    }
                }
            }

            if (grid[i][j] == 'G') good.push_back({i, j});
        }
    }

    vector<vector<bool>> vis(55, vector<bool>(55, false));

    // dfs from end point to all the non wall positions
    function<void(vector<int>)> dfs = [&](vector<int> node) {
        for (int z = 0; z < 4; z++) {
            int r = node[0] + dr[z];
            int c = node[1] + dc[z];

            if (r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c] != '#') {
                vis[r][c] = true;
                dfs({r, c});
            }
        }
    };

    if (grid[n - 1][m - 1] != '#') {
        vis[n - 1][m - 1] = true;
        dfs({n - 1, m - 1});
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((grid[i][j] == 'G' && !vis[i][j]) || (grid[i][j] == 'B' && vis[i][j])) {
                cout << "No" << endl;
                return;
            }
        }
    }
    cout << "Yes" << endl;
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