#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.length() != s2.length()) {
        cout << "NO" << endl;
        return;
    }
    if (s1 == s2) {
        cout << "YES" << endl;
        return;
    }
    if (s1.length() == 1) {
        cout << "NO" << endl;
        return;
    }
    bool isPos1 = false, isPos2 = false;
    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] == '1') isPos1 = true;
        if (s2[i] == '1') isPos2 = true;
    }
    if (isPos1 && isPos2)
        cout << "YES" << endl;
    else
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