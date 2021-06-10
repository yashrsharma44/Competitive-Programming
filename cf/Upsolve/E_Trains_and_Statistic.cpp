
#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

const int maxn = 1 << 18;
pair<int, int> tree[maxn * 2];

void build(const vector<int> &a, int n) {
    for (int i = 0; i < n; i++) tree[maxn + i] = {a[i], i};
    for (int i = maxn - 1; i > 0; i--)
        tree[i] = max(tree[i * 2], tree[i * 2 + 1]);
}

int get(int l, int r) {
    pair<int, int> ans{-1, -1};
    for (l += maxn, r += maxn + 1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) ans = max(ans, tree[l++]);
        if (r & 1) ans = max(ans, tree[--r]);
    }
    return ans.second;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }

    build(a, n);

    // dp[i] gives us the sum for all the values from [i, n-1]
    // dp[i] = dp[m] + (n - 1 - a[i]) + (m - i)
    // Here m is the index of the maximum element in a[i:a[i]+1]
    // For elements from i-m, we need 1 ticket to reach j = [i+1, m]
    // for reaching to j=[m+1, n-1], we need to reach m, where we can reach
    // the j, using the smallest count using 1 + dp[m] steps
    // so for ith step, sum of call counts is:
    // (m - i) * 1 for any step between [i+1, m]
    // note that we are skipping between [m+1, a[i]], because that is taken care
    // by dp[m] :P
    // dp[m] + [1 * (n - 1 - a[i])] for step between [m, n-1]

    vector<int> dp(n, 0);
    dp[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--) {
        int m = get(i + 1, a[i]);
        dp[i] = dp[m] + (n - 1 - a[i]) + (m - i);
    }

    int total = 0;
    for (int i = 0; i < n; i++) total += dp[i];

    cout << total << endl;
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