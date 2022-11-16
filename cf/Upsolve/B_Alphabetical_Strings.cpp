#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    string s;
    cin >> s;

    int n = s.length();

    int l = -1, r = -1;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == 'a') {
            l = r = i;
            break;
        }
    }

    if (l == -1) {
        cout << "NO" << endl;
        return;
    }

    for (int i = 1; i <= 26; i++) {
        // cout << l << " " << r << " " << i << endl;
        if ((r - l) + 1 == n) {
            cout << "YES" << endl;
            return;
        }
        if (l - 1 >= 0 && s[l - 1] - 'a' == i) {
            l--;
        } else if (r + 1 < n && s[r + 1] - 'a' == i) {
            r++;
        } else {
            cout << "NO" << endl;
            return;
        }
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