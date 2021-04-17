#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();
    auto palin = [&](string ss) {
        int l = 0, r = ss.length() - 1;
        while (l < r) {
            if (ss[l] != ss[r]) return false;
            l++;
            r--;
        }
        return true;
    };
    if (!palin(s + 'a')) {
        cout << "YES" << endl;
        cout << s << 'a' << endl;
        return;
    } else if (!palin('a' + s)) {
        cout << "YES" << endl;
        cout << 'a' << s << endl;
        return;
    } else {
        cout << "NO" << endl;
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