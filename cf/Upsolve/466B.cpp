#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    set<vector<int>> factors;
    for (int i = 1; i * i <= (6 * n); i++) {
        if ((6 * n) % i == 0) {
            factors.insert({i, (6 * n) / i});
        }
    }

    int ans = -1;
    vector<int> fact;
    for (auto fc : factors) {
        int v1 = fc[0], v2 = fc[1];
        if (v1 >= a && v2 >= b) {
            if (ans > v1 * v2) {
                ans = v1 * v2;
                fact = {v1, v2};
            }
        }
    }

    cout << ans << endl;
    cout << fact[0] << " " << fact[1] << endl;
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