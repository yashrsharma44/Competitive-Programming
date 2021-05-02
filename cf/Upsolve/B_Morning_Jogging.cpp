#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m, -1));
    multiset<int> elems;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            elems.insert(a[i][j]);
        }
    }
    vector<vector<int>> ans(n, vector<int>(m, -1));
    while (elems.size() > m) {
        elems.erase(elems.find(*elems.rbegin()));
    }

    int p = 0;
    for (int i = 0; i < n; i++) {
        // make a list of mins, and put them strategically
        multiset<int> nums, rem;

        for (int j = 0; j < m; j++) {
            rem.insert(a[i][j]);
            if (elems.count(a[i][j]) > 0) {
                nums.insert(a[i][j]);
                elems.erase(elems.find(a[i][j]));
                rem.erase(rem.find(a[i][j]));
            }
        }

        // put the mins
        while (p < m && nums.size() > 0) {
            ans[i][p] = *nums.begin();
            nums.erase(nums.find(ans[i][p]));
            p++;
        }
        // put the rem ones
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == -1) {
                ans[i][j] = *rem.begin();
                rem.erase(rem.find(ans[i][j]));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << " \n"[j == m - 1];
        }
    }
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