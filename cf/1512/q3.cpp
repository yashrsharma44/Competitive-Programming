#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;

    for (auto el : s) {
        if (el == '0')
            a--;
        else if (el == '1')
            b--;
    }

    int p1 = 0, p2 = s.length() - 1;
    while (p1 < p2) {
        if (s[p1] != '?' && s[p2] != '?') {
            if (s[p1] != s[p2]) {
                cout << -1 << endl;
                return;
            }
        } else {
            if (!(s[p1] == '?' && s[p2] == '?')) {
                if (s[p1] == '?') {
                    if (s[p2] == '0') {
                        s[p1] = '0';
                        a--;
                    } else {
                        s[p1] = '1';
                        b--;
                    }
                    if (a < 0 || b < 0) {
                        cout << -1 << endl;
                        return;
                    }
                } else if (s[p2] == '?') {
                    if (s[p1] == '1') {
                        s[p2] = '1';
                        b--;
                    } else {
                        s[p2] = '0';
                        a--;
                    }
                    if (a < 0 || b < 0) {
                        cout << -1 << endl;
                        return;
                    }
                }
            }
        }
        p1++;
        p2--;
    }

    p1 = 0;
    p2 = s.length() - 1;
    while (p1 < p2) {
        if (s[p1] == '?' && s[p2] == '?') {
            if (a > b) {
                s[p1] = '0';
                s[p2] = '0';
                a -= 2;
            } else {
                s[p1] = '1';
                s[p2] = '1';
                b -= 2;
            }
            if (a < 0 || b < 0) {
                cout << -1 << endl;
                return;
            }
        }
        p1++;
        p2--;
    }

    int m = s.length() / 2;
    if (s[m] == '?') {
        if (a > 0) {
            s[m] = '0';
            a -= 1;
        } else if (b > 0) {
            s[m] = '1';
            b -= 1;
        } else {
            cout << -1 << endl;
            return;
        }
    }
    if (a != 0 || b != 0) {
        cout << -1 << endl;
        return;
    }
    cout << s << endl;
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
