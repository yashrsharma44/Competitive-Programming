#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> b(n + 2);
    int sum = 0;
    map<int, int> mp;
    for (int i = 0; i < n + 2; i++) {
        cin >> b[i];
        sum += b[i];
        mp[b[i]]++;
    }
    vector<int> ans;
    for (auto el : b) {
        int ai = sum - el;
        if (ai % 2 == 0 && mp.count(ai / 2) > 0) {
            // x is el
            // sum of ai..n is ai / 2
            mp[el] -= 1;
            mp[ai / 2] -= 1;
            for (auto e : mp) {
                while (e.second > 0) {
                    ans.push_back(e.first);
                    e.second -= 1;
                }
            }
            if (ans.size() == n)
                break;

            ans.clear();
            mp[el]++;
            mp[ai / 2]++;
        }
    }
    if (ans.size() != n) {
        cout << -1 << endl;
        return;
    }
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
