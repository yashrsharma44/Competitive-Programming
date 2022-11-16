#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<string> solve(string s) {
    vector<string> ans;
    if (s.length() == 0) return ans;
    vector<int> cnt(26, 0);
    for (auto el : s) {
        cnt[el - 'a']++;
    }

    int odd = 0;
    string pre = "", post = "", center = "";

    for (int i = 0; i <= 26; i++) {
        char ch = (char)('a' + i);
        int val = cnt[i];

        if (val % 2 == 1) {
            odd++;
            if (odd > 1) return {};
            val--;
            center = ch;
        }

        val = val >> 1;
        while (val > 0) {
            pre += ch;
            val--;
        }
    }

    sort(pre.begin(), pre.end());
    // try all permutation
    while (true) {
        post = "";
        for (int i = pre.size() - 1; i >= 0; i--) {
            post += pre[i];
        }

        ans.push_back(pre + center + post);
        if (!next_permutation(pre.begin(), pre.end())) break;
    }
    return ans;
}

int32_t main() {
    auto ans = solve("ababb");
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
}