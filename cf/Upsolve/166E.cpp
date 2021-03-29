#include <bits/stdc++.h>
// #define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;

    function<int(int, int)> dp = [&](int vert, int count) {
        if (count == 1) return 1;

        int sum = 0;
        for (int i = 0; i < 4; i++) {
            if (i != vert) {
                sum += dp(i, count - 1);
                sum %= MOD;
            }
        }
        return sum;
    };

    int ans = dp(0, n);
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}