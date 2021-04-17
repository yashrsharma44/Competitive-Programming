#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    function<int()> dp = [&](int i, vector<int> count, int k) {
        if (i >= n) return 0;
        int ans = 0;
        // choose this number
        int el = a[i];
        int z = 0;
        while (el > 0) {
            count[z++] = el % 2;
            el /= 2;
        }

        int cnt = 0;
        for (int)

            // skip this number
            ans = max(ans, dp(i + 1, count, k));
    };
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