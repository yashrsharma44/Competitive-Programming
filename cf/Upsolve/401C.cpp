#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    if (m > (2 * n + 2) || m < n) {
        if (m + 1 == n) {
            cout << 0;
            while (m--) {
                cout << "10";
            }
            cout << endl;
            return;
        }
        cout << -1 << endl;
        return;
    }
    vector<string> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back("10");
    }
    m -= n;
    vector<string> ans;
    for (auto el : arr) {
        if (m > 0) {
            m -= 1;
            ans.push_back("1");
        }
        ans.push_back(el);
    }
    while (m-- > 0) ans.push_back("1");
    for (auto el : ans) {
        for (auto e : el) {
            cout << e;
        }
    }
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}