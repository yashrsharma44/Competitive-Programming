#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<vector<int>> cost(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> cost[i][j];

    // first modify this into rlefied array
    vector<int> rle;
    map<int, int> count;

    int last = c[0];
    int idx = 0;
    count[idx] = 1;
    for (int i = 1; i < n; i++) {
        if (last == c[i])
            count[idx]++;
        else {
            rle.push_back(last);
            last = c[i];
            idx++;
            count[idx]++;
        }
    }
    rle.push_back(last);

    // verify if initial distinct rles <= k
    int initial = 0;
    for (auto el : rle) {
        if (el != 0) initial++;
    }

    if (initial > k) {
        cout << -1 << endl;
        return;
    }

    // do a dp :P
    function<int()> dp = [&](int i) {
        if (i == rle.size()) {
            return 0;
        }

        if (rle[i] != 0) return dp(i + 1);

        // for zero element, we have 3 choices
        // color zero element same as left
        // color zero element same as right
        // color zero element distinct

        // also if count of zero is > 1
        // we can color some same as left, other as right
    };
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