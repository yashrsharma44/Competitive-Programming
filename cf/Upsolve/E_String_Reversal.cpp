#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    // lets reverse the string and count the number of inversions
    // in the string wrt to original string.
    // Inversions, give us the number of swaps required.

    // We also want to minimize the number of swaps(so minimize) the
    // number of inversions. So if there are duplicate characters
    // while reversing, choose the nearest character.
    // For example - a b c a d
    //              [1 2 3 4 5]
    //              [5 4 3 2 1] ->Inv Count = 4 + 3 + 2 + 1 = 10
    // Choose this -[5 1 3 2 4] ->Inv Count = 4 + 0 + 1 + 0 + 0 = 5
    // Reversed    - d a c b a
    vector<int> chars[26];
    for (int i = 0; i < n; i++) {
        chars[s[i] - 'a'].push_back(i);
    }
    for (int i = 0; i < 26; i++) {
        sort(chars[i].begin(), chars[i].end(), greater<int>());
    }

    vector<int> perm;
    for (int i = n - 1; i >= 0; i--) {
        perm.push_back(chars[s[i] - 'a'].back());
        chars[s[i] - 'a'].pop_back();
    }

    function<int(vector<int> &, vector<int> &, int, int, int)> merge = [&](vector<int> &a, vector<int> &temp, int l, int m, int r) {
        int count = 0;
        int p1 = l, p2 = m, p3 = l;
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
        int m, inv_count = 0;
        if (l < r) {
            m = (l + r) >> 1;
            inv_count += mergeSort(a, temp, l, m);
            inv_count += mergeSort(a, temp, m + 1, r);

            inv_count += merge(a, temp, l, m + 1, r);
        }
        return inv_count;
    };

    auto inv = [&](vector<int> &a) {
        vector<int> temp(n, -1);
        return mergeSort(a, temp, 0, n - 1);
    };

    int ans = inv(perm);
    cout << ans << endl;
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