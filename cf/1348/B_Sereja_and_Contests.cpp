#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int x, k;
    cin >> x >> k;
    set<int> nums;
    for (int i = 1; i < x; i++) nums.insert(i);

    // for (auto el : nums) cout << el << " ";
    // cout << endl;
    for (int i = 0; i < k; i++) {
        int u;
        cin >> u;
        if (u == 1) {
            int v, w;
            cin >> v >> w;
            nums.erase(v);
            nums.erase(w);
        } else {
            int v;
            cin >> v;
            nums.erase(v);
        }
    }
    vector<int> left(nums.begin(), nums.end());
    int max_ = left.size();
    int min_ = 0;
    for (int i = 0; i < left.size();) {
        if (left[i] + 1 == left[i + 1]) {
            min_ += 1;
            i += 2;
        } else {
            min_ += 1;
            i += 1;
        }
    }
    cout << min_ << " " << max_ << endl;
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