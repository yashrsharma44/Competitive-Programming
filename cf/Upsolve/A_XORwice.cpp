#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
        int a, b;
    cin >> a >> b;
    int x = a & b;
    // cout << "X" << x << endl;
    int ans = a ^ x;
    // cout << "P" << ans << endl;
    ans += b ^ x;
    cout << ans << endl;
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