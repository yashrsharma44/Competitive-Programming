#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int el : a) {
        if (el < 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    cout << 300 << endl;
    for (int i = 0; i < 300; i++) {
        cout << i << " \n"[i == 299];
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}