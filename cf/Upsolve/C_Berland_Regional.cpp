#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> u(n), s(n);
    for (int i = 0; i < n; i++) cin >> u[i];
    for (int i = 0; i < n; i++) cin >> s[i];

    unordered_map<int, multiset<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[u[i]].insert(s[i]);
    }

    map<int, vector<int>> mp2;
    for (auto &el : mp) {
        auto st = el.second;
        // sort(vec.begin(), vec.end());
        vector<int> vec(st.begin(), st.end());
        vec.push_back(0);
        reverse(vec.begin(), vec.end());

        mp2[el.first] = vec;
    }

    // for (auto el : mp) {
    //     cout << el.first << endl;
    //     for (auto e : el.second) cout << e << " ";
    //     cout << endl;
    // }
    for (auto &el : mp2) {
        int univ = el.first;
        auto skill = el.second;
        for (int i = 1; i < skill.size(); i++) {
            skill[i] += skill[i - 1];
        }
        el.second = skill;
    }

    for (int k = 1; k <= n; k++) {
        vector<int> erse;
        int tot = 0;
        for (auto &el : mp2) {
            int sz = (int)(el.second.size()) - 1;
            if (sz < k) {
                erse.push_back(el.first);
                continue;
            }

            int q = sz / k;
            int cnt = q * k;
            int ans = el.second[cnt];
            tot += ans;
        }
        cout << tot << " ";

        // erase the smaller ones
        for (auto el : erse) {
            mp2.erase(el);
        }
    }
    cout << endl;
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