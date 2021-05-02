#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

class Comparator {
   public:
    bool operator()(vector<int> &p1, vector<int> &p2) {
        return p1[0] > p2[0];
    }
};
int rowWeight[505][505];
int colWeight[505][505];

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    // vector<vector<int>> rowWeight(n, vector<int>(m - 1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            cin >> rowWeight[i][j];
        }
    }
    // vector<vector<int>> colWeight(n - 1, vector<int>(m, -1));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> colWeight[i][j];
        }
    }
    if (k % 2 == 1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << -1 << " \n"[j == m - 1];
            }
        }
        return;
    }
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    auto valid = [&](int r, int c) {
        return r >= 0 && r < n && c >= 0 && c < m;
    };

    auto fact = [&](int num) {
        set<int> ans;
        for (int i = 1; i * i <= num; i++) {
            if (num % i == 0) {
                ans.insert(i);
                ans.insert(num / i);
            }
        }

        return vector<int>(ans.begin(), ans.end());
    };

    // vector<vector<int>> ans(n, vector<int>(m, INT_MAX));
    vector<int> facts = fact(k / 2);

    // lets do a dijkstras and choose the min possible cost from (i, j) to any point at a distance z
    int dist[n + 1][m + 1][k + 1];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int z = 0; z < k; z++) {
                dist[i][j][z] = LLONG_MAX;
            }
        }
    }

    // value of distance for all points at a distance 0 is zero
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            dist[i][j][0] = 0;
        }
    }

    // lets do a multisource dijkstras, and get the min possible cost at a distance i
    priority_queue<vector<int>, vector<vector<int>>, Comparator> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pq.push({0, i, j, 0});
            //    weight, r, c, level
        }
    }

    auto cost = [&](int sr, int sc, int fr, int fc) {
        if (sr == fr) {
            return rowWeight[fr][min(sc, fc)];
        }
        return colWeight[min(sr, fr)][fc];
    };

    while (!pq.empty()) {
        auto node = pq.top();
        pq.pop();

        int r = node[1], c = node[2], w = node[0], l = node[3];
        if (dist[r][c][l] < w) continue;

        for (int z = 0; z < 4; z++) {
            int rr = r + dr[z];
            int cc = c + dc[z];

            if (valid(rr, cc) && (dist[rr][cc][l + 1] > w + cost(r, c, rr, cc))) {
                dist[rr][cc][l + 1] = w + cost(r, c, rr, cc);
                if (l + 1 < (k / 2))
                    pq.push({dist[rr][cc][l + 1], rr, cc, l + 1});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int ans = INT_MAX;
            for (auto f : facts) {
                ans = min(ans, (k / f) * dist[i][j][f]);
            }
            cout << ans << " \n"[j == m - 1];
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << ans << " \n"[j == m - 1];
    //     }
    // }
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