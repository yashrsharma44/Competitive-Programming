#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 1; i <= n; i *= 2) {
        ans.push_back(i);
        n -= i;
    }
    if (n > 0) ans.push_back(n);
    sort(ans.begin(), ans.end());
    cout << ans.size() - 1 << endl;
    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] - ans[i - 1] << " ";
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