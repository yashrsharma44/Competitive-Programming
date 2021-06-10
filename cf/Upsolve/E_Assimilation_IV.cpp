#include <bits/stdc++.h>
#define int long long
#define MOD 998244353
using namespace std;

int mod_pow(int base, int exp) {
    if (exp == 0) return 1LL;
    if (exp & 1) return (base * mod_pow(base, exp - 1)) % MOD;
    return mod_pow((base * base) % MOD, exp >> 1) % MOD;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> d(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> d[i][j];

    vector<int> fac(n + 1, 0);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % MOD;

    vector<int> fac_inv(n + 1, 0);
    fac_inv[n] = mod_pow(fac[n], MOD - 2);

    for (int i = n - 1; i >= 0; i--) {
        fac_inv[i] = (fac_inv[i + 1] * (i + 1)) % MOD;
    }

    auto calc = [&](int j) {
        vector<int> cnt(n + 1, 0);
        for (int i = 0; i < n; i++) cnt[(n + 1) - d[i][j]]++;

        int ans = 1;
        int total = 0;

        for (int step = 0; step < n; step++) {
            total += (cnt[step]);
            ans *= (total - step);
            ans %= MOD;
        }

        int ret = (fac[n] - ans) * fac_inv[n];
        ret %= MOD;
        return ret;
    };

    int ans = 0;
    for (int j = 0; j < m; j++) {
        ans += calc(j);
        ans %= MOD;
    }
    ans += MOD;
    ans %= MOD;

    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}