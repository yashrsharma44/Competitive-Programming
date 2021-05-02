#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n = 3, m = 4;
    vector<vector<int>> a({{7, 3, 3, 1}, {4, 8, 3, 6}, {7, 7, 7, 3}});
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    vector<vector<int>> dp2(n + 1, vector<int>(m + 1, 0));
    dp[0][1] = a[0][0];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = max(dp[i - 1][j] & a[i - 1][j - 1], dp[i][j - 1] & a[i - 1][j - 1]);
        }
    }

    dp2[1][1] = a[0][0];
    for (int i = 2; i <= n; i++) {
        dp2[i][1] = dp2[i - 1][1] & a[i - 1][0];
    }

    for (int i = 2; i <= m; i++) {
        dp2[1][i] = dp2[1][i - 1] & a[0][i - 1];
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            dp2[i][j] = max(dp2[i - 1][j] & a[i - 1][j - 1], dp2[i][j - 1] & a[i - 1][j - 1]);
        }
    }

    cout << "Matrix:\n";
    for (auto el : a) {
        for (auto e : el) {
            cout << e << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "Question DP:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Correct DP:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << dp2[i][j] << " ";
        }
        cout << endl;
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