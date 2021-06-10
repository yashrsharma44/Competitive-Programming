#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m, b, mod;
    cin >> n >> m >> b >> mod;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int MAX = 505;
    int dp[2][505][505];

    // Lets use an iterative approach

    // If we skip the ith programmer
    // dp(i, rem, sum) += dp(i-1, rem, sum)

    // If ith programmer does atleast 1 work
    // dp(i, rem, sum) += dp(i-1, rem - 1, sum - a[i])

    vector<vector<int>> new_dp(m + 1, vector<int>(b + 1, 0));
    for (int rem = 0; rem <= m; rem++) {
        for (int sum = 0; sum <= b; sum++) {
            if (rem == 0)
                new_dp[rem][sum] = 1;
            else
                new_dp[rem][sum] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        vector<vector<int>> prev(m + 1, vector<int>(b + 1, 0));
        prev = new_dp;
        new_dp = vector<vector<int>>(m + 1, vector<int>(b + 1, 0));

        for (int rem = 0; rem <= m; rem++) {
            for (int sum = 0; sum <= b; sum++) {
                // get the parity of prev index, should be opposite of current parity.
                int id = (i & 1) ^ 1;

                new_dp[rem][sum] = prev[rem][sum];
                if (rem - 1 >= 0 && sum - a[i - 1] >= 0) {
                    new_dp[rem][sum] = new_dp[rem][sum] + new_dp[rem - 1][sum - a[i - 1]];
                    new_dp[rem][sum] %= mod;
                }
            }
        }
    }

    cout << new_dp[m][b] << endl;
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