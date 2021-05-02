#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    // 1/2 - index
    // R/L
    vector<vector<int>> ans;

    string t = s.substr(1, n - 2);
    reverse(t.begin(), t.end());
    ans.push_back({1, 1});

    s = s + t;
    t = s.substr(1, 1);
    ans.push_back({2, 1});

    s = t + s;
    n = s.length();
    t = s.substr(1, n - 2);
    reverse(t.begin(), t.end());
    ans.push_back({1, 1});

    s = s + t;
    n = s.length();
    t = s.substr(n - 2, 1);
    s = s + t;
    ans.push_back({1, n - 2});
    // cout << s << endl;
    cout << ans.size() << endl;
    for (auto el : ans) {
        if (el[0] == 1)
            cout << "R ";
        else
            cout << "L ";
        cout << el[1] + 1 << endl;
    }
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