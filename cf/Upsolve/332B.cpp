#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
#define pi acos(-1)

int getSum(vector<int> &pre, int l, int r) {
    return pre[r] - pre[l - 1];
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
    }

    int ans = getSum(pre, n - 2 * k, n);
    vector<int> ansi = {n - 2 * k, n - k};

    int suf_max = getSum(pre, n - k, n);
    vector<int> suf_maxi = {} for (int i = n - 2 * k; i >= 0; i--) {
        int local_suf = getSum(pre, i, i + k);
        if (local_suf >= suf_max) {
            local_suf = suf_max;
        }
    }
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