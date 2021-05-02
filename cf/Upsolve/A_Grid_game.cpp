#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    string s;
    cin >> s;
    int v = 0, h = 0;
    for (auto ch : s) {
        if (ch == '1')
            h++;
        else
            v++;
    }
    map<int, vector<string> > mp;
    vector<string> horPos({"1 1", "2 1", "3 1", "4 1"});
    for (int i = 0; i < h; i++) {
        mp[1].push_back(horPos[i % 4]);
    }

    vector<string> verPos({"1 4", "3 4"});
    for (int i = 0; i < v; i++) {
        mp[0].push_back(verPos[i % 2]);
    }

    vector<string> hor = mp[1], ver = mp[0];
    // reverse(hor.begin(), hor.end());
    // reverse(ver.begin(), ver.end());

    for (auto ch : s) {
        if (ch == '1') {
            cout << hor.back() << endl;
            hor.pop_back();
        } else {
            cout << ver.back() << endl;
            ver.pop_back();
        }
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