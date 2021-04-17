#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<char, int> cnt;
    for (auto el : s) cnt[el]++;
    if (cnt['T'] != 2 * cnt['M']) {
        cout << "NO" << endl;
        return;
    }

    vector<int> count(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') count[i] = 1;
        if (i > 0)
            count[i] += count[i - 1];
    }
    int right = cnt['M'];
    int left = 1;

    for (int i = 0; i < n; i++) {
        if (s[i] == 'M') {
            if (count[i] >= left && cnt['T'] - count[i] >= right) {
                right -= 1;
                left += 1;
            } else {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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