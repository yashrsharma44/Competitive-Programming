#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    if (n < 2050) {
        cout << -1 << endl;
        return;
    }
    int cnt = 0;
    int num = 2050 * (int)(pow(10, 15));
    while (n > 0 && num > 0) {
        while (num > n) {
            num /= 10;
        }

        // num <= n
        int q = n / num;
        cnt += q;
        n -= q * num;
        if (n < 2050) break;
    }
    if (n == 0) {
        cout << cnt << endl;
        return;
    }
    cout << -1 << endl;
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