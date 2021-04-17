#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;

    int total_width = 0;
    vector<vector<int>> book(n);
    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        book[i] = {u, v};
        total_width += u;
    }
    // sort books wrt to horizontal width
    sort(book.begin(), book.end(), [&](vector<int> &p1, vector<int> &p2) {
        if (p1[1] != p2[1])
            return p1[1] < p2[1];
        return p1[0] < p2[0];
    });
    int ans = total_width;
    int curr_width = total_width;
    int booksize = 0;
    for (int i = 0; i < n; i++) {
        if (curr_width - book[i][0] >= booksize + book[i][1]) {
            curr_width -= book[i][0];
            ans = min(ans, curr_width);
            booksize += book[i][1];
        }
    }

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