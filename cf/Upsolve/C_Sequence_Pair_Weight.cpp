#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, int> mp;

    vector<int> dp(n, 0);
    mp[a[0]]++;
    for (int i = 1; i < n; i++) {
        // cout << i << " " << mp[a[i]] << endl;
        dp[i] = dp[i - 1] + mp[a[i]];
        mp[a[i]] += (i + 1);
        // cout << i << " " << dp[i] << endl;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) ans += dp[i];
    cout << ans << endl;
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