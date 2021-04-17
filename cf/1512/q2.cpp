#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int r1 = -1, r2 = -1, c1 = -1, c2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') {
                if (r1 == -1) {
                    r1 = i;
                    c1 = j;
                } else {
                    r2 = i;
                    c2 = j;
                }
            }
        }
    }

    if (r1 != r2 && c1 != c2) {
        int r3 = r1, c3 = c2, r4 = r2, c4 = c1;
        grid[r3][c3] = '*';
        grid[r4][c4] = '*';
    } else if (r1 == r2) {
        int r3 = (r1 + 1) % n, c3 = c1, r4 = (r2 + 1) % n, c4 = c2;
        grid[r3][c3] = '*';
        grid[r4][c4] = '*';
    } else {
        int r3 = r1, c3 = (c1 + 1) % n, r4 = r2, c4 = (c2 + 1) % n;
        grid[r3][c3] = '*';
        grid[r4][c4] = '*';
    }
    for (auto el : grid) {
        for (auto e : el) {
            cout << e;
        }
        cout << endl;
    }
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
