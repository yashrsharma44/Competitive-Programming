#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> ans;
    auto sum = [](int el) {
        int sm = 0;
        while (el > 0) {
            sm += el % 10;
            el /= 10;
        }
        return sm;
    };
    for (int k = 0; k <= 81; k++) {
        int x = b * pow(k, a) + c;
        if (x > 0 && x < 1000000000 && sum(x) == k) {
            ans.push_back(x);
        }
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
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}