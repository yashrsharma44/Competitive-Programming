#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> a[i][j];
    }

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    // mark the row and column which contains zero as unusable
    // and then find the sum of row/col
    // verify the row, col and diagonals if valid
    // then substitute val of zero

    int row = -1, col = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0) {
                row = i;
                col = j;
                break;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        if (i == row) continue;
        for (int j = 0; j < n; j++) {
            sum += a[i][j];
        }
        break;
    }

    auto verify = [&](bool skipCheck) {
        // check row
        for (int i = 0; i < n; i++) {
            if (!skipCheck && i == row) continue;
            int local = 0;
            for (int j = 0; j < n; j++) local += a[i][j];

            if (sum != local) return false;
        }

        // check column
        for (int i = 0; i < n; i++) {
            if (!skipCheck && col == i) continue;
            int local = 0;
            for (int j = 0; j < n; j++) local += a[j][i];

            if (sum != local) return false;
        }

        // check  diags
        if (skipCheck || row != col) {
            int local = 0;
            for (int i = 0; i < n; i++) {
                local += a[i][i];
            }
            if (local != sum) return false;
        }

        if (skipCheck || row != n - 1 - col) {
            // cout << "Y" << endl;
            int local = 0;
            for (int i = 0; i < n; i++) {
                local += a[i][n - 1 - i];
            }
            // cout << local << endl;

            if (local != sum) return false;
        }

        return true;
    };

    // check if 0  element satisfies the sum
    // if (verify(true)) {
    //     cout << 0 << endl;
    //     return;
    // }

    if (!verify(false)) {
        cout << -1 << endl;
        return;
    }

    // find zero element
    int rem = 0;
    for (int i = 0; i < n; i++) {
        rem += a[i][col];
    }
    a[row][col] = sum - rem;
    if (verify(true) && sum - rem > 0) {
        cout << sum - rem << endl;
        return;
    }
    cout << -1 << endl;
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