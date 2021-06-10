#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;

    // k = n - k;
    auto getSum = [&](int r) {
        cout << "? " << 1 << " " << r << endl;
        fflush(stdout);
        int val;
        cin >> val;
        return val;
    };

    int l = 1, r = n + 1;
    // find first el such that pos - sum >= k
    // first True

    while (l < r) {
        int m = (l + r) >> 1;
        if (m - getSum(m) >= k)
            r = m;
        else
            l = m + 1;
    }

    cout << "! " << l << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << " " << (i - getSum(i) >= k) << endl;
    // }
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