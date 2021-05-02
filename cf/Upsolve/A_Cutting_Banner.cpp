#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    string a;
    cin >> a;
    int n = a.length();
    if (n < 10) {
        cout << "NO" << endl;
        return;
    }

    // find the subsequence of codeforces
    string b = "CODEFORCES";
    if (a.substr(0, 10) == b || a.substr(n - 10, 10) == b) {
        cout << "YES" << endl;
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // cut out a[i:j+1]
            string c = a.substr(0, i + 1) + a.substr(j);
            if (c == b) {
                cout << "YES" << endl;
                return;
            }
            // string d = a.substr(i, j - i + 1);
            // if (d == b) {
            //     cout<<
            //     cout << "YES" << endl;
            //     return;
            // }
        }
    }
    cout << "NO" << endl;
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