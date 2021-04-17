#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= 10; i++) {
        int val = i - 1;
        int sm = val * (val + 1) / 2 + 1;
        cout << i << " " << (sm >= n) << endl;
    }
    // first true
    int l = 1, r = k;
    while (l < r) {
        int m = (l + r) >> 1;
        int val = m - 1;
        int sm = (((val) * (val + 1)) / 2) + 1;

        if (sm >= n)
            r = m;
        else
            l = m + 1;
    }
    cout << l << endl;
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