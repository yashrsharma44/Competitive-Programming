#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;

    if (n < 11) {
        cout << "NO" << endl;
        return;
    }

    if (n % 11 == 0) {
        cout << "YES" << endl;
        return;
    }

    for (int i = 1; i <= min((int)1e6, n); i++) {
        int rem = n - (111 * i);
        if (rem >= 0 && rem % 11 == 0) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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