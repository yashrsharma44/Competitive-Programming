#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    // for each digit, find the smallest and largest roww and col
    // if parallel, then put the 3rd point at corners
    // else choose point on the first/last row/col parallel to the points

    for (int i = 0; i <= 9; i++) {
        int maxArea = 0;

        // find the minrow and maxrow
        int minrow = n, maxrow = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] - '0' == i) {
                    minrow = min(minrow, r);
                    maxrow = max(maxrow, r);
                }
            }
        }

        // lets position 3rd point parallel to (i, j) and choose minRow or maxRow
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] - '0' == i) {
                    int h1 = abs(minrow - r), h2 = abs(r - maxrow);
                    int l1 = abs(c - 0), l2 = abs(n - c - 1);

                    maxArea = max({maxArea, max(h1, h2) * max(l1, l2)});
                }
            }
        }

        int mincol = n, maxcol = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] - '0' == i) {
                    mincol = min(mincol, c);
                    maxcol = max(maxcol, c);
                }
            }
        }

        // lets position 3rd point parallel to (i, j) and choose minCol or maxCol
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] - '0' == i) {
                    int l1 = abs(c - mincol), l2 = abs(c - maxcol);
                    int h1 = abs(r - 0), h2 = abs(n - 1 - r);

                    maxArea = max({maxArea, max(h1, h2) * max(l1, l2)});
                }
            }
        }

        cout << maxArea << " ";
    }
    cout << endl;
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