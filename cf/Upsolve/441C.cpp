#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> grid(n, vector<int>(m, -1));
    int local = 2;
    k -= 1;
    int kk = k + 1;
    if (k != 0)
        cout << 2 << " ";
    bool isTwo = false;
    for (int i = 0; i < n; i++) {
        if (k == 0) break;
        if (i % 2 == 1) {
            for (int j = 0; j < m; j++) {
                if (k == 0) break;
                if (local > 0) {
                    isTwo = true;
                    grid[i][j] = k;
                    cout << i + 1 << " " << j + 1 << " ";
                    local -= 1;
                } else {
                    k -= 1;

                    if (k == 0) break;

                    isTwo = true;
                    cout << endl
                         << "2 ";

                    grid[i][j] = k;
                    cout << i + 1 << " " << j + 1 << " ";
                    local = 1;
                }
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                if (k == 0) break;
                if (local > 0) {
                    isTwo = true;
                    grid[i][j] = k;
                    cout << i + 1 << " " << j + 1 << " ";
                    local -= 1;
                } else {
                    k -= 1;

                    if (k == 0) break;
                    cout << endl
                         << "2 ";

                    isTwo = true;
                    grid[i][j] = k;
                    cout << i + 1 << " " << j + 1 << " ";
                    local = 1;
                }
            }
        }
    }
    bool first = false;
    if (isTwo) cout << endl;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 1) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == -1) {
                    if (!first) {
                        cout << n * m - (kk - 1) * 2 << " ";
                        first = true;
                    }
                    cout << i + 1 << " " << j + 1 << " ";
                }
            }
        } else {
            for (int j = m - 1; j >= 0; j--) {
                if (grid[i][j] == -1) {
                    if (!first) {
                        cout << n * m - (kk - 1) * 2 << " ";
                        first = true;
                    }
                    cout << i + 1 << " " << j + 1 << " ";
                }
            }
        }
    }
    cout << endl;
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