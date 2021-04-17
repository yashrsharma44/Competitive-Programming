#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int len = max(s1.length(), s2.length());
    set<string> v1, v2;
    auto divisor = [&](string &a, int l) {
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != a[i % l]) return false;
        }
        return a.length() % l == 0;
    };
    for (int i = 1; i * i <= len; i++) {
        if (divisor(s1, i)) v1.insert(s1.substr(0, i));
        if (divisor(s1, len / i)) v1.insert(s1.substr(0, len / i));

        if (divisor(s2, i)) v2.insert(s2.substr(0, i));
        if (divisor(s2, len / i)) v2.insert(s2.substr(0, len / i));
    }

    vector<string> ans(len);
    auto ls = set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), ans.begin());
    cout << ls - ans.begin() << endl;
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