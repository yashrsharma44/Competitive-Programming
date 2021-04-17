#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;
    vector<string> rle;
    string last = s.substr(0, 1);
    for (int i = 1; i < n; i++) {
        if (last[0] == s[i])
            last += s[i];
        else {
            rle.push_back(last);
            last = s.substr(i, 1);
        }
    }
    rle.push_back(last);

    for (int i = 0; i < rle.size(); i++) {
        if (rle[i].size() == 1) continue;

        int size = rle[i].size();
        if (rle[i].size() == 2) {
            if (i + 1 < rle.size()) {
                set<char> pos({'R', 'G', 'B'});
                pos.erase(rle[i][0]);
                pos.erase(rle[i + 1][0]);
                rle[i][size - 1] = *pos.begin();
            } else if (i - 1 >= 0) {
                set<char> pos({'R', 'G', 'B'});
                pos.erase(rle[i][0]);
                pos.erase(rle[i - 1].back());
                rle[i][0] = *pos.begin();
            } else {
                // we have only 1 rlefied string, choose any
                set<char> pos({'R', 'G', 'B'});
                pos.erase(rle[i][0]);
                rle[i][0] = *pos.begin();
            }
            ans++;
        } else {
            // handle the case for odd and even
            if (rle[i].size() % 2 == 1) {
                // odd
                // replace the odd pos
                set<char> pos({'R', 'G', 'B'});
                pos.erase(rle[i][0]);
                for (int z = 1; z < rle[i].size(); z += 2) {
                    rle[i][z] = *pos.begin();
                    ans++;
                }
            } else {
                // even case
                set<char> pos({'R', 'G', 'B'});
                pos.erase(rle[i][0]);

                rle[i][1] = *pos.begin();
                ans++;

                for (int z = 2; z < rle[i].size(); z += 2) {
                    rle[i][z] = *pos.rbegin();
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;
    for (auto el : rle) cout << el;
    cout << endl;
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