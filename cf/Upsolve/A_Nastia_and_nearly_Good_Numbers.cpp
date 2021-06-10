#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int A, B;
    cin >> A >> B;
    if (B == 1) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << A * B << " " << A << " " << A * (B + 1) << endl;
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