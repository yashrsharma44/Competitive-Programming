#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<char> type(n);
    for (int i = 0; i < n; i++) cin >> type[i];

    // treat even and odd positions independently
    vector<pair<int, char>> even, odd;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0)
            even.push_back({a[i], type[i]});
        else
            odd.push_back({a[i], type[i]});
    }

    sort(even.begin(), even.end());
    sort(odd.begin(), odd.end());

    vector<int> ans(n, -1);
    auto cal = [&](vector<pair<int, char>> &arr) {
        // check for (R L)
        // move those first
        for (int i = 1; i < arr.size();) {
            if (arr[i].second == 'L' && arr[i - 1].second == 'R') {
                int p1 = arr[i - 1].first;
                int p2 = arr[i].first;

                ans[p1] = (p2 - p1) >> 1;
                ans[p2] = (p2 - p1) >> 1;
                i += 2;
            } else
                i++;
        }
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