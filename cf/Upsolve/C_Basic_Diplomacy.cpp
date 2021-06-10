#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> aval;
    vector<vector<int>> mp;
    for (int i = 0; i < m; i++) {
        int k;
        cin >> k;
        vector<int> val(k);
        for (int j = 0; j < k; j++) cin >> val[j];
        mp.push_back({k, i});
        aval.push_back(val);
    }

    sort(mp.begin(), mp.end());
    vector<int> ans(m + 1, -1);
    vector<int> count(n + 1, 0);

    // for each day, choose the min count friend
    // if we cannot choose, answer is impossible

    for (int i = 0; i < m; i++) {
        int min_cnt = INT_MAX;
        int min_friend = 0;

        int row = mp[i][1];

        for (int el : aval[row]) {
            if (count[el] < min_cnt) {
                min_cnt = count[el];
                min_friend = el;
            }
        }

        if (min_cnt >= ((m + 1) / 2)) {
            cout << "NO" << endl;
            return;
        }
        ans[row] = min_friend;
        count[min_friend]++;
    }

    cout << "YES" << endl;
    for (int i = 0; i < m; i++) cout << ans[i] << " ";
    cout << endl;
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