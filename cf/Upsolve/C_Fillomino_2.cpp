#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void printAns(vector<vector<int>> &ans, int n) {
    cout << "ANS:\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " \n"[j == n];
        }
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++) cin >> p[i];
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++) {
        ans[i][i] = p[i];
    }

    auto valid = [&](int r, int c) {
        return r >= 1 && r <= n && c >= 1 && c <= n;
    };

    // auto

    for (int i = 1; i <= n; i++) {
        int el = p[i];
        // for each cell, go left and go down
        int dr[2] = {0, 1};
        int dc[2] = {-1, 0};
        // go left
        int r = i, c = i;
        int cnt = p[i];
        cnt -= 1;
        while (cnt > 0) {
            int k = 0;
            while (cnt > 0 && k < 2) {
                // while (cnt > 0) {
                int rr = r + dr[k];
                int cc = c + dc[k];

                if (!valid(rr, cc) || ans[rr][cc] != -1) {
                    k++;
                    continue;
                }
                ans[rr][cc] = el;
                r = rr;
                c = cc;
                cnt--;
                if (k == 1) k++;
            }
            // }
            // printAns(ans, n);
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << ans[i][j] << " \n"[j == i];
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