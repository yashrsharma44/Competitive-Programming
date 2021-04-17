#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;

    map<int, int> mp;
    mp[0] = 1;
    int count = 0;
    int pre = 0;
    for (auto el : s) {
        int val = el - '0';
        pre += val;
        mp[pre]++;
    }

    for (auto pr : mp) {
        int el = pr.first;
        if (mp.count(el - k) > 0) {
            if (k != 0) {
                count += mp[el] * mp[el - k];
            } else if (mp[el] >= 2) {
                int val = mp[el];
                int ans = (val) * (val - 1) / 2;
                count += ans;
            }
        }
    }
    cout << count << endl;
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