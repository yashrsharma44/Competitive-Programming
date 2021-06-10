#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<vector<int>, int> cnt;

    int d = 0, k = 0;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'D')
            d++;
        else
            k++;

        if (k == 0 || d == 0) {
            if (k == 0) {
                cnt[{0, 1}] += 1;
                ans.push_back(cnt[{0, 1}]);
            } else {
                cnt[{1, 0}] += 1;
                ans.push_back(cnt[{1, 0}]);
            }

        } else {
            int kk = k, dd = d;
            while (__gcd(kk, dd) != 1) {
                int div = __gcd(kk, dd);
                kk /= div;
                dd /= div;
            }
            cnt[{kk, dd}]++;
            ans.push_back(cnt[{kk, dd}]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
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