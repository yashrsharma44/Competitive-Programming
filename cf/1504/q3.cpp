#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    if (s[0] != '1' || s[n - 1] != '1') {
        cout << "NO" << endl;
        return;
    }

    int one = 0, zero = 0;
    for (auto ch : s) {
        if (ch == '1')
            one++;
        else
            zero++;
    }

    if (one % 2 == 1) {
        cout << "NO" << endl;
        return;
    }

    vector<char> a1(n), a2(n);
    int o = 0, z = 0;
    for (int i = 0; i < n; i++) {
        char ch = s[i];
        if (ch == '1') {
            if (o % 2 == 0) {
                a1[i] = '(';
                a2[i] = '(';
            } else {
                a1[i] = ')';
                a2[i] = ')';
            }
            o++;
        } else {
            if (z % 2 == 0) {
                a1[i] = '(';
                a2[i] = ')';
            } else {
                a1[i] = ')';
                a2[i] = '(';
            }
            z++;
        }
    }
    cout << "YES" << endl;
    for (auto ch : a1) cout << ch;
    cout << endl;
    for (auto ch : a2) cout << ch;
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