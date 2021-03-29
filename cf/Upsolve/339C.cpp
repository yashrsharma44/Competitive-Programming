#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> ans;

    std::function<bool(int, int, vector<int>, int, bool)> dfs = [&](int bal, int id, vector<int> loc, int last, bool sub) {
        if (id >= m) {
            for (auto el : loc) {
                ans.push_back(el);
            }
            return true;
        }

        // for all the possibilities, choose the one which flips the sign
        for (int i = 0; i < 10; i++) {
            if (s[i] == '1' && i != last) {
                int new_bal = sub == true ? bal - (i + 1) : bal + (i + 1);
                if (new_bal >= 0 && bal >= 0 || new_bal <= 0 && bal <= 0) continue;
                loc.push_back(i + 1);
                if (dfs(new_bal, id + 1, loc, i, !sub)) return true;
                loc.pop_back();
            }
        }
        return false;
    };

    for (int i = 1; i <= 10; i++) {
        if (s[i - 1] == '1') {
            vector<int> comp;
            comp.push_back(i);
            if (dfs(i, 1, comp, i - 1, true)) {
                cout << "YES" << endl;
                for (auto el : ans) cout << el << " ";
                cout << endl;
                return;
            }
        }
    }
    cout << "NO" << endl;
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