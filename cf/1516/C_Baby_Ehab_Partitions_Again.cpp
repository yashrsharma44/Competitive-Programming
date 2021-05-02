#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int sum = 0;
    for (auto el : a) sum += el;
    if (sum % 2 == 1) {
        cout << 0 << endl;
        return;
    }

    // check with knapsack if a subset occurs of equal sum
    vector<vector<int>> cache(n, vector<int>(2000 * 100 + 5, -1));

    function<bool(int, int)> dp = [&](int i, int rem) {
        if (rem < 0) return false;
        if (i >= n) {
            return rem == 0;
        }
        if (cache[i][rem] != -1) return cache[i][rem] == 1;
        cache[i][rem] = (dp(i + 1, rem - a[i]) || dp(i + 1, rem)) ? 1 : 2;
        return cache[i][rem] == 1;
    };

    bool isPart = dp(0, sum / 2);
    if (!isPart) {
        cout << 0 << endl;
        return;
    }

    // remove the element whose val becomes odd after division
    while (true) {
        for (int i = 0; i < n; i++) {
            int el = a[i];
            if (el % 2 == 1) {
                cout << 1 << endl;
                cout << i + 1 << endl;
                return;
            }
            a[i] /= 2;
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