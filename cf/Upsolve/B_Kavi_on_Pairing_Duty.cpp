#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    vector<int> D(1e6 + 5, 0);
    D[0] = 1;
    for (int i = 1; i < 1e6 + 5; i++) {
        for (int j = i; j < 1e6 + 5; j += i) {
            D[j]++;
        }
    }

    vector<int> dp(n + 1, 0);
    int pre = 1;
    dp[0] = dp[1] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i] = (D[i] + pre);
        dp[i] %= MOD;
        pre = (pre + dp[i]);
        pre %= MOD;
    }

    cout << dp[n] << endl;
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