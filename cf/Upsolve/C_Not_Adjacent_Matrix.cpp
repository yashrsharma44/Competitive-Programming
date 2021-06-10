#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n == 2) {
        cout << -1 << endl;
        return;
    }
    if (n == 3) {
        cout << "2 9 7\n";
        cout << "4 6 3\n";
        cout << "1 8 5\n";
        return;
    }
    int ctr = 1;
    vector<vector<int>> ans(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j += 2) {
            ans[i][j] = ctr++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n; j += 2) {
            ans[i][j] = ctr++;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << ans[i][j] << " \n"[j == n];
        }
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