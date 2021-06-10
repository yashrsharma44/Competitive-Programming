#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> grid[i][j];

    // count all # characters, answer is 2**(count(#))
    // if all # present, we want 1 placeholder to be 0
    // so 2**(count(#)) - 1
    int cnt = 0;
    bool zero = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') cnt++;
            if (grid[i][j] == '0') zero = true;
        }
    }

    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        ans *= 2;
        ans %= MOD;
    }
    if (!zero) ans -= 1;
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}