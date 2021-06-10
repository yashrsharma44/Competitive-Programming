#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<int>> a(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }

    vector<vector<int>> copy = a;

    sort(a.rbegin(), a.rend());
    multiset<vector<int>> ms;
    for (int i = 0; i < m; i++) ms.insert({0, i});

    vector<int> ans(n, -1);
    for (auto el : a) {
        auto top = *ms.begin();
        ms.erase(ms.find(top));

        top[0] += el[0];
        ans[el[1]] = (top[1]);
        ms.insert(top);
    }

    vector<int> arr(m, 0);
    for (int i = 0; i < n; i++) {
        arr[ans[i]] += copy[i][0];

        // for (auto el : arr) {
        //     cout << el << " ";
        // }
        // cout << endl;
    }

    // check if adjacent is <= x

    for (int i = 0; i < arr.size(); i++) {
        // cout << arr[i] << " ";
        if ((i > 0 && abs(arr[i] - arr[i - 1]) > x) || (i < arr.size() - 1 && abs(arr[i] - arr[i + 1]) > x)) {
            cout << "NO" << endl;
            return;
        }
    }
    // cout << endl;

    cout << "YES" << endl;
    for (auto el : ans) {
        cout << el + 1 << " ";
    }
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