#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(a.begin(), a.end());
    int M1 = MOD, M2 = (int)1e9 + 207;
    int last = M1;
    vector<vector<int>> ans;
    for (int i = 0; i < n - 1; i++) {
        if (min(a[i], a[i + 1]) == a[i]) {
            // change a[i+1]
            a[i + 1] = last;
            ans.push_back({i + 1, i + 2, a[i], last});
        } else {
            // change a[i]
            a[i] = last;
            ans.push_back({i + 1, i + 2, last, a[i + 1]});
        }
        if (last == M1)
            last = M2;
        else
            last = M1;
    }
    // for (auto el : a) {
    //     cout << el << " ";
    // }
    // cout << endl;
    // for (int i = 0; i < n; i++) {
    //     if (a[i] != b[i]) ans.push_back({i + 1, i + 2, a[i], a[i + 1]});
    // }

    cout << ans.size() << endl;
    for (auto el : ans) {
        for (auto e : el) {
            cout << e << " ";
        }
        cout << endl;
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