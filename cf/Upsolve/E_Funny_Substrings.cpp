#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<string> stat(n + 1);

    for (int i = 0; i < n + 1; i++) {
        getline(cin, stat[i], '\n');
    }

    // cout << endl;
    vector<vector<string>> ans;
    auto parse = [&](string s) {
        vector<string> res;
        string ss = "";
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != ' ') {
                ss += s[i];
            } else {
                res.push_back(ss);
                ss = "";
            }
        }
        if (ss != "") {
            res.push_back(ss);
        }
        return res;
    };

    for (auto el : stat) {
        if (el.length() > 0)
            ans.push_back(parse(el));
    }
    map<string, vector<string>> adj;

    map<string, string> mp;
    for (auto entry : ans) {
        if (entry.size() == 3) {
            // assign
            mp[entry[0]] = entry[2];
        } else {
            // create graph
            adj[entry[0]].push_back(entry[2]);
            adj[entry[0]].push_back(entry[4]);
        }
    }


    string haha = "haha";
    string last = "";
    if (ans.size() > 0) {
        last = ans.back()[0];
    }

    function<string(string)> dp = [&](string node){
        
    };

    // lets do a dp
    last = dp(last);


    int cnt = 0;
    // cout << last << endl;
    for (int i = 0; i < last.length(); i++) {
        if (haha[0] == last[i]) {
            // cout << last[i] << " " << i << endl;
            int z = 0;
            while (z < 4 && haha[z] == last[i + z]) {
                z++;
            }
            if (z == 4) cnt++;
        }
    }

    cout << cnt << endl;
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