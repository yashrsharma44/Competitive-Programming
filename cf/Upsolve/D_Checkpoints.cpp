#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int k;
    cin >> k;
    if (k % 2 == 1) {
        cout << -1 << endl;
        return;
    }
    int LIMIT = 60;
    vector<int> ans({1});
    k -= 2;
    while (k > 0) {
        if (k % 2 == 1) {
            cout << -1 << endl;
            return;
        }
        int x_i = 0;
        int last = x_i;
        int i = 0;
        for (i = 0; i < LIMIT; i++) {
            int xi_1 = 2 * (x_i + 1);
            if (xi_1 <= k) {
                last = xi_1;
            } else {
                break;
            }
            x_i = xi_1;
        }

        for (int j = 0; j < i - 1; j++) ans.push_back(0);
        ans.push_back(1);
        k -= last;
    }
    cout << ans.size() << endl;
    for (auto el : ans) cout << el << " ";
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