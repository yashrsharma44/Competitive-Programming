#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> mp(100005, 0LL);
    int mx = -1;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        mp[u] += 1;
        mx = max(mx, u);
    }

    vector<int> cache(100005, -1);

    function<int(int)> dp = [&](int i) {
        if (i <= 0) return 0LL;
        if (i == 1) return mp[i];

        if (cache[i] != -1) return cache[i];

        // choose current
        int sum = 0LL;
        sum = max(sum, i * mp[i] + dp(i - 2));
        sum = max(sum, dp(i - 1));

        return cache[i] = sum;
    };

    int ans = dp(mx + 1);
    // for (int i = 0; i <= 10; i++) {
    //     cout << i << " " << dp(i) << endl;
    // }
    cout << ans << endl;
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