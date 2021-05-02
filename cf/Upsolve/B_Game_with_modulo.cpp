#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int r, b, d;
    cin >> r >> b >> d;
    if (r < b) swap(r, b);

    // r is big
    int cnt = r / (d + 1);
    if (r % (d + 1) != 0) cnt++;

    if (b >= cnt) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
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