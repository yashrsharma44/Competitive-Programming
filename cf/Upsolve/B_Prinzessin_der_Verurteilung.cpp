#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    function<bool(int, string)> dfs = [&](int idx, string ss) {
        if (idx == 0) {
            // cout << ss << endl;
            // check if ss is a substring
            for (int z = 0; z < n; z++) {
                if (s[z] == ss[0]) {
                    int j = 0;
                    while (j < ss.length() && s[z + j] == ss[j]) j++;
                    if (j == ss.length()) {
                        return false;
                    }
                }
            }

            cout << ss << endl;
            return true;
        }
        for (int ch = 0; ch < 26; ch++) {
            if (dfs(idx - 1, ss + string(1, ('a' + ch)))) return true;
        }
        return false;
    };

    int i = 1;
    while (true) {
        bool isPos = dfs(i, "");
        if (isPos) {
            return;
        }
        i++;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}