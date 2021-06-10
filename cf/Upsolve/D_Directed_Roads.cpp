#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

map<string, int> solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> grid[i][j];
    }

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    function<void(int, int, set<char> &)> dfs = [&](int r, int c, set<char> &comp) {
        int dr[4] = {1, 0, -1, 0};
        int dc[4] = {0, 1, 0, -1};

        for (int z = 0; z < 4; z++) {
            int rr = r + dr[z];
            int cc = c + dc[z];

            if (rr >= 0 && rr < n && cc >= 0 && cc < m && !vis[rr][cc] && grid[rr][cc] != '#') {
                comp.insert(grid[rr][cc]);
                vis[rr][cc] = true;
                dfs(rr, cc, comp);
            }
        }
    };

    // connected components
    map<string, int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] != '#' && !vis[i][j]) {
                vis[i][j] = true;
                set<char> comp({grid[i][j]});
                dfs(i, j, comp);
                comp.erase('.');
                // for (auto el : comp) {
                //     cout << el << " ";
                // }
                // cout << endl;
                if (comp.size() > 1) {
                    ans["contested"]++;
                } else if (comp.size() == 1) {
                    string key(1, (*comp.begin()));
                    // cout << "K: " << key << endl;
                    ans[key]++;
                }
            }
        }
    }

    return ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    for (int tt = 1; tt <= t; tt++) {
        cout << "Case " << tt << ": " << endl;
        auto ans = solve();
        int v = ans["contested"];
        ans.erase("contested");
        for (auto el : ans) {
            cout << el.first << " " << el.second << endl;
        }
        cout << "contested " << v << endl;
        // cout << endl;
    }
}