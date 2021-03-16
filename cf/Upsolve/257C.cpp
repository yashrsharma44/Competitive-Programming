#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;
#define pi acos(-1)

void solve() {
    int n;
    cin >> n;

    vector<vector<int> > points(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) cin >> points[i][0] >> points[i][1];

    vector<double> rad;
    for (int i = 0; i < n; i++) {
        double angle = atan2(points[i][1], points[i][0]);
        rad.push_back(angle);
    }
    sort(rad.begin(), rad.end());

    double ans = 0;
    for (int i = 1; i < n; i++) {
        double diff = (rad[i] - rad[(i - 1)]);
        ans = max(ans, diff);
    }
    ans = max(ans, rad[0] - rad.back() + 2 * pi);
    // cout << ans << endl;
    double angle = 360 - ((double)180 / pi) * ans;
    printf("%08f\n", angle);
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