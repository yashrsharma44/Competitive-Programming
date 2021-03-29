#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        mp[u] += 1;
    }

    multiset<vector<int>> ms;
    for (auto el : mp) {
        ms.insert({el.second, el.first});
    }

    while (ms.size() > 1) {
        auto b1 = *ms.rbegin();
        ms.erase(ms.find(b1));

        auto b2 = *ms.rbegin();
        ms.erase(ms.find(b2));

        b1[0] -= 1;
        b2[0] -= 1;

        if (b1[0] != 0) {
            ms.insert(b1);
        }
        if (b2[0] != 0) {
            ms.insert(b2);
        }
    }

    if (ms.size() == 0) {
        cout << 0 << endl;
        return;
    }
    auto ans = *ms.begin();
    cout << ans[0] << endl;
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