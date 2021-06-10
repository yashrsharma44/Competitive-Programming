#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> ans;

    auto print = [&]() {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << ".\n"[i == (int)(ans.size()) - 1];
        }
    };

    int len = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i] == 1) {
            ans.push_back(a[i]);
            print();
            continue;
        }

        int j = ans.size() - 1;

        while (ans.size() > 0) {
            if (a[i] - ans.back() == 1) {
                ans.pop_back();
                break;
            }
            ans.pop_back();
        }
        ans.push_back(a[i]);
        print();
    }
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