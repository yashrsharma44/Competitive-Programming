#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> points(n, vector<int>(2, 0));

    for (int i = 0; i < n; i++) cin >> points[i][0];
    for (int i = 0; i < n; i++) cin >> points[i][1];

    // for (auto el : points) cout << el[0] << " " << el[1] << endl;
    // cout << endl;
    points.push_back({1, 1});
    sort(points.begin(), points.end());

    int cost = 0;
    int oldr = points[0][0], oldc = points[0][1];
    for (int i = 1; i < points.size(); i++) {
        int curr = points[i][0], curc = points[i][1];

        if (curr - oldr == curc - oldc) {
            // diagonal
            int diff = curr - oldr;
            if ((oldr + oldc) % 2 == 0) {
                cost += diff;
            }
        } else {
            // move (curr, curc) -> (diffR + 1, diffC + 1)
            int diffR = curr - oldr + 1;
            int diffC = curc - oldc + 1;

            if ((oldr + oldc) % 2 == 0) {
                cost += (diffR - diffC) / 2;
            } else {
                cost += (diffR - diffC + 1) / 2;
            }
        }
        oldr = points[i][0];
        oldc = points[i][1];
    }
    cout << cost << endl;
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