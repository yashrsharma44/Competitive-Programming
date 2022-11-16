#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    string a;
    cin >> a;

    int n = a.length();

    vector<int> chars[26];
    for (int i = 0; i < n; i++) chars[a[i] - 'A'].push_back(i);

    function<int(vector<int> &, vector<int> &, int, int, int)> merge = [&](vector<int> &a, vector<int> &temp, int l, int m, int r) {
        int p1 = l, p2 = m, p3 = l;
        int count = 0;

        while (p1 < m and p2 <= r) {
            if (a[p1] <= a[p2])
                temp[p3++] = a[p1++];
            else {
                temp[p3++] = a[p2++];
                count += (m - p1);
            }
        }

        while (p1 < m) temp[p3++] = a[p1++];
        while (p2 <= r) temp[p3++] = a[p2++];

        for (int i = l; i <= r; i++) a[i] = temp[i];
        return count;
    };

    function<int(vector<int> &, vector<int> &, int, int)> mergeSort = [&](vector<int> &a, vector<int> &temp, int l, int r) {
        int count = 0;
        if (l < r) {
            int m = (l + r) >> 1;
            count += mergeSort(a, temp, l, m);
            count += mergeSort(a, temp, m + 1, r);

            count += merge(a, temp, l, m + 1, r);
        }
        return count;
    };

    auto inv = [&](string s) {
        vector<int> perm;
        for (auto ch : s) {
            for (auto el : chars[ch - 'A']) perm.push_back(el);
        }
        vector<int> temp(n, -1);
        return mergeSort(perm, temp, 0, n - 1);
    };

    int ans = 0;
    string rv = "ANOT";
    string ansS = "ANOT";

    do {
        // cout << "perm: " << rv << endl;
        int cnt = inv(rv);
        if (cnt > ans) {
            ans = cnt;
            ansS = rv;
        }
    } while (next_permutation(rv.begin(), rv.end()));

    // cout << ans << endl;
    for (auto ch : ansS) {
        int len = chars[ch - 'A'].size();
        while (len > 0) {
            cout << ch;
            len--;
        }
    }
    cout << endl;
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