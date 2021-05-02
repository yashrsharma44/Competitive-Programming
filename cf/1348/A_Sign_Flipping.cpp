#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) {
            // odd pos +ve
            if (a[i - 1] <= 0) a[i - 1] = -a[i - 1];
        } else {
            // even pos -ve
            if (a[i - 1] >= 0) a[i - 1] = -a[i - 1];
        }
    }
    for (auto el : a) cout << el << " ";
    cout << endl;
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