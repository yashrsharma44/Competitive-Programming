#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> cache(12, vector<int>(200005, -1));
    function<int(int, int)> dp = [&](int num, int op) {
        // cout << num << "->" << op << endl;

        if (op == 0) {
            // count number of digits of num and return them
            int len = 0;
            while (num > 0) {
                len++;
                num /= 10;
            }
            return len;
        }
        if (cache[num][op] != -1) return cache[num][op];

        if (num == 10) return cache[num][op] = dp(2, op - 1) + dp(1, op - 1);

        int ans = 0;
        int cpy = num;
        while (cpy > 0) {
            ans += dp((cpy % 10) + 1, op - 1);
            cpy /= 10;
        }

        return cache[num][op] = ans;
    };

    int ans = 0;
    while (n > 0) {
        int digit = n % 10;
        ans += dp(digit, m);
        ans %= MOD;
        n /= 10;
    }

    // for (int i = 1; i <= 11; i++) {
    //     cout << cache[i][6] << " ";
    // }
    // cout << endl;

    // ans %= MOD;
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