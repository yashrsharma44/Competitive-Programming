#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<int>> diam(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        diam[i][0] = 1;
        diam[i][m - 1] = 1;
    }
    for (int i = 0; i < m; i++) {
        diam[0][i] = 1;
        diam[n - 1][i] = 1;
    }

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            if (a[i][j] != a[i - 1][j]) diam[i][j] = diam[i - 1][j] = 1;
            if (a[i][j] != a[i + 1][j]) diam[i][j] = diam[i + 1][j] = 1;
            if (a[i][j] != a[i][j - 1]) diam[i][j] = diam[i][j - 1] = 1;
            if (a[i][j] != a[i][j + 1]) diam[i][j] = diam[i][j + 1] = 1;
        }
    }

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    queue<vector<int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (diam[i][j] == 1) q.push({i, j});
        }
    }

    while (!q.empty()) {
        auto node = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int rr = node[0] + dr[k];
            int cc = node[1] + dc[k];

            if (valid(rr, cc) && diam[rr][cc] == 0) {
                diam[rr][cc] = diam[node[0]][node[1]] + 1;
                q.push({rr, cc});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += diam[i][j];
        }
    }

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