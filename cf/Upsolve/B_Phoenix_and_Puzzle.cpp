#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    int num = n;

    if (n % 2 != 0) {
        cout << "NO" << endl;
        return;
    }

    n /= 2;
    int pw = sqrt(n);
    if (pw * pw == n) {
        cout << "YES" << endl;
        return;
    }

    // check 4 ka even power

    n = num;
    if (n % 4 != 0) {
        cout << "NO" << endl;
        return;
    }
    n /= 4;

    pw = sqrt(n);
    if (pw * pw == n) {
        cout << "YES" << endl;
        return;
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