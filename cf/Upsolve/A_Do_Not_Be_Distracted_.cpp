#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    char last = s[0];

    set<char> elems({last});
    for (int i = 1; i < n; i++) {
        if (s[i] == last)
            continue;
        else {
            if (elems.count(s[i]) > 0) {
                cout << "NO" << endl;
                return;
            }
            last = s[i];
            elems.insert(last);
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