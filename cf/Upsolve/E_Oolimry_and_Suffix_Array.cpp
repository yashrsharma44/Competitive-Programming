#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

auto mul = [&](int a, int b) {
    return ((a % MOD) * (b % MOD)) % MOD;
};

int poww(int b, int e) {
    if (e <= 0) return 1;
    if (b <= 0) return 0;

    int ans = 1;
    while (e) {
        if (e & 1) {
            ans = mul(ans, b);
        }
        b = mul(b, b);
        e >>= 1;
    }
    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    vector<int> prior(n + 1, -1);
    k--;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prior[arr[i]] = i;
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        if (prior[arr[i] + 1] > prior[arr[i + 1] + 1]) cnt++;
    }

    if (k - cnt < 0) {
        cout << 0 << endl;
        return;
    }

    auto inv = [&](int val) {
        return poww(val, MOD - 2);
    };

    // cout << k << " " << cnt << endl;

    // calculate comb(N+R-1, N), N = k - cnt, R = n+1
    int ans = 1LL;
    int N = k - cnt, R = n + 1;
    // cout << "N: " << N << " R: " << R << endl;
    for (int i = 1; i < R; i++) {
        ans = mul(ans, N + i);
        ans = mul(ans, inv(i));
    }

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