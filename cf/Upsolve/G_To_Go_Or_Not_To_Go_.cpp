#include <bits/stdc++.h>
#define int int64_t
int MOD = (int)1e9 + 7;

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};

void solve() {
    int n, m, w;
    cin >> n >> m >> w;
    vector<vector<int>> a(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];

    int MAX = 1e18;
    auto bfs = [&](int sr, int sc) {
        // bfs from (n, m) to all the points
        // single source shortest path to all the points

        vector<vector<int>> distance(n, vector<int>(m, MAX));
        queue<vector<int>> q;
        q.push({0, sr, sc});

        while (!q.empty()) {
            auto node = q.front();
            q.pop();
            int weight = node[0], row = node[1], col = node[2];

            if (distance[row][col] < w) continue;
            distance[row][col] = weight;
            for (int z = 0; z < 4; z++) {
                int rr = row + dr[z];
                int cc = col + dc[z];

                if (rr >= 0 && rr < n && cc >= 0 && cc < m && a[rr][cc] != -1) {
                    if (distance[rr][cc] == MAX || distance[rr][cc] > w + distance[row][col]) {
                        distance[rr][cc] = w + distance[row][col];
                        q.push({distance[rr][cc], rr, cc});
                    }
                }
            }
        }
        return distance;
    };

    // Lets calculate the dist from (n-1, m-1) to all the points
    auto dist = bfs(n - 1, m - 1);

    // Lets calculate the dist from (0, 0) to all the points
    auto dist2 = bfs(0, 0);
    // find all the portals
    vector<vector<int>> portals;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] > 0) portals.push_back({i, j});
        }
    }

    // consider pair of portals, and see if we can minimize our answer
    int ans = dist[0][0];

    for (int i = 0; i < portals.size(); i++) {
        for (int j = 0; j < portals.size(); j++) {
            if (i == j) continue;
            int r1 = portals[i][0], c1 = portals[i][1];
            int r2 = portals[j][0], c2 = portals[j][1];

            ans = min(ans, a[r1][c1] + a[r2][c2] + dist2[r1][c1] + dist[r2][c2]);
            // cout << a[r1][c1] << " " << a[r2][c2] << " " << dist2[r1][c1] << " " << dist[r2][c2] << endl;
        }
    }

    cout << ((ans >= MAX) ? -1 : ans) << endl;
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