#include <bits/stdc++.h>
#define int long long

using namespace std;

int MOD = (int)(1e9 + 7);
int total;
int f(int n, int k, int turn, vector<vector<vector<int>>> &cache) {
    if (k == 0) return 0LL;
    if (n == 0) return 1LL;

    if (cache[n][k][turn] != -1) return cache[n][k][turn];
    int sum = 1LL;
    if (turn == 0) {
        for (int i = 1; i <= n; i++) {
            sum += f(n - i, k - 1, 1, cache);
            sum %= MOD;
        }
    } else {
        for (int i = n + 1; i <= total; i++) {
            sum += f(i - n, k - 1, 0, cache);
            sum %= MOD;
        }
    }
    return cache[n][k][turn] = sum;
}

void solve() {
    int n, k;
    cin >> n >> k;
    total = n;
    vector<vector<vector<int>>> cache(1005, vector<vector<int>>(1005, vector<int>(2, -1)));
    int ans = f(n, k, 0, cache);
    ans %= MOD;
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