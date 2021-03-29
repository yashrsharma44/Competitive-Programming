#include <bits/stdc++.h>
// #define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    vector<int> nums;
    int itr = 0;
    for (auto ch : s) {
        if (ch == '*') {
            nums.push_back(itr);
        }
        itr += 1;
    }
    vector<int> cache(100, -1);
    function<int(int)> dp = [&](int i) {
        int N = nums.size();

        if (cache[i] != -1) return cache[i];
        if (nums[i] - nums[0] <= k) return cache[i] = 1;

        int ans = INT_MAX;
        for (int j = 0; j < i; j++) {
            if (nums[i] - nums[j] <= k) {
                ans = min(ans, 1 + dp(j));
            }
        }

        return cache[i] = ans;
    };
    int ans = 1;
    if (nums.size() >= 2) {
        ans = 1 + dp(nums.size() - 1);
    }
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
