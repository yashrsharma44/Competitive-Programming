#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    string s;
    cin >> s;
    string ss;
    cin >> ss;
    vector<int> cnt(26);
    for (int i = 0; i < 26; i++) cnt[i] = ss[i] - '0';
    int k;
    cin >> k;

    int n = s.length();
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (cnt[s[i - 1] - 'a'] == 0) {
            pre[i] = 1;
        }
        pre[i] += pre[i - 1];
    }
    vector<string>
        ans;
    auto isAbsent = [&](string u) {
        int l = 0, r = ans.size() - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (ans[m] == u)
                return false;
            else if (ans[m].compare(u) < 0) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        return true;
    };

    for (int i = 1; i <= n; i++) {
        string aa = "";
        for (int j = i; j <= n; j++) {
            aa += s[j - 1];
            if (pre[j] - pre[i - 1] <= k) {
                if (isAbsent(aa))
                    ans.push_back(aa);
            }
        }
    }

    cout << ans.size() << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
}