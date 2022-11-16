#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    function<int(int)> func = [&](int mx) {
        int ans = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (a[l] + a[r] <= mx) {
                ans += (r - l);
                l++;
            } else
                r--;
        }
        return ans;
    };

    int cnt1 = func(r), cnt2 = func(l - 1);
    // cout << cnt1 << " " << cnt2 << endl;
    cout << cnt1 - cnt2 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}