#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    string prefix = s.substr(0, k);
    // check if prefix has all same characters
    bool isSame = true;
    char first = s[0];
    for (auto ch : prefix) {
        if (ch != first) isSame = false;
    }

    if (!isSame) {
        cout << s[k - 1] << endl;
        return;
    }
    // check remaining suffix has same characters
    // if yes, distribute evenly
    // else add it to one of the starting chars
    string suffix = s.substr(k, n - k);
    isSame = true;
    first = s[k];
    for (auto ch : suffix) {
        if (ch != first) isSame = false;
    }

    if (!isSame) {
        cout << s[0] + suffix << endl;
        return;
    }
    string ans = "";
    for (int i = 0; i < n; i += k) ans += s[i];
    cout << ans << endl;
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