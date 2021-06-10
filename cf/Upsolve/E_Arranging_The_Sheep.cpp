#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // prefix and suffix
    // (count, sum)
    vector<vector<int>> pre(n + 1, vector<int>(2, 0));
    vector<vector<int>> suf(n + 2, vector<int>(2, 0));

    int lastPos = 0;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '*') {
            pre[i][1] = (pre[i - 1][0]) * (i - lastPos - 1) + pre[i - 1][1];
            pre[i][0] += pre[i - 1][0] + 1;
            lastPos = i;
        } else {
            pre[i][1] += pre[i - 1][1];
            pre[i][0] += pre[i - 1][0];
        }
    }

    lastPos = n + 1;
    for (int i = n; i >= 0; i--) {
        if (s[i - 1] == '*') {
            suf[i][1] = (suf[i + 1][0]) * (lastPos - i - 1) + suf[i + 1][1];
            suf[i][0] += suf[i + 1][0] + 1;
            lastPos = i;
        } else {
            suf[i][0] += suf[i + 1][0];
            suf[i][1] += suf[i + 1][1];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     cout << pre[i][0] << " " << pre[i][1] << endl;
    // }
    // cout << endl;

    // for (int i = 1; i <= n; i++) {
    //     cout << suf[i][0] << " " << suf[i][1] << endl;
    // }

    int ans = LLONG_MAX;
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '*') {
            ans = min(ans, pre[i][1] + suf[i][1]);
        }
    }
    if (ans == LLONG_MAX) ans = 0;
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