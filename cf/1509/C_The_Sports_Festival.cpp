#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> count;
    for (auto el : a) count[el]++;

    vector<vector<int>> arr;
    for (auto el : count) {
        arr.push_back({el.first, el.second});
    }

    sort(arr.begin(), arr.end());
    // for (auto el : arr) {
    //     for (int i = 0; i < n; i++) {
    //         if (el[0] == a[i]) {
    //             cout << i + 1 << " " << a[i] << endl;
    //             break;
    //         }
    //     }
    // }

    int ans = LLONG_MAX;
    int max_ = arr.back()[0];

    vector<int> preCount({0});
    vector<int> pre({0});
    for (auto el : arr) {
        pre.push_back(pre.back() + el[0] * el[1]);
        preCount.push_back(preCount.back() + el[1]);
    }
    int size = arr.size();
    for (int i = 0; i < size; i++) {
        int prev = pre[i];
        int next = pre.back() - pre[i + 1];

        int sum = next - (n - preCount[i + 1]) * arr[i][0];
        sum += (preCount[i]) * max_ - prev;

        if (sum < ans) {
            ans = min(ans, sum);
            // cout << arr[i][0] << " " << arr[i][1] << endl;
        }
    }

    cout << ans << endl;
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