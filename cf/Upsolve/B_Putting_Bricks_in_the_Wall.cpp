#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) cin >> grid[i];

    int A = grid[1][0] - '0', B = grid[0][1] - '0', C = grid[n - 1][n - 2] - '0', D = grid[n - 2][n - 1] - '0';
    vector<vector<int>> ans;
    if (A == B) {
        // put C and D opposite of A
        if (C == A)
            ans.push_back({n - 1, n - 2});
        if (D == A)
            ans.push_back({n - 2, n - 1});
    } else if (C == D) {
        // put A and B opposite of C
        if (A == C)
            ans.push_back({1, 0});
        if (B == C)
            ans.push_back({0, 1});
    } else {
        // A!=B and C!=D
        // set A and B equal
        A = B;
        ans.push_back({1, 0});

        // set C and D diff from A
        if (C == A)
            ans.push_back({n - 1, n - 2});
        if (D == A)
            ans.push_back({n - 2, n - 1});
    }
    cout << ans.size() << endl;
    for (auto el : ans) cout << el[0] + 1 << " " << el[1] + 1 << endl;
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