#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
using namespace std;

void solve() {
    int x, y;
    cin >> x >> y;
    vector<int> c(6);
    for (int i = 0; i < 6; i++) cin >> c[i];
    // X, Y
    // up/down, right/left

    int right = y - x;
    int upright = x;
    int upleft = -y;
    vector<int> val({right, upright, upleft});
    // make sure the right and upright is +ve and upleft is negative
    // else we need to rotate the coordinate axis anti-clockwise
    while (!(right >= 0 && upright >= 0 && upleft <= 0)) {
        // right becomes upright
        // upright becomes upleft
        // upleft becomes right
        right = -val[1];
        upright = -val[2];
        upleft = -val[0];
        val = {right, upright, upleft};
        int first = c[0];
        c.erase(c.begin());
        c.push_back(first);
    }
    // for (auto el : c) {
    //     cout << el << " ";
    // }
    // cout << endl;
    // cout << upleft << " " << right << " " << upright << endl;
    int c1 = c[0], c2 = c[1], c3 = c[2], c4 = c[3], c5 = c[4], c6 = c[5];
    // for going right,
    // we have 2 choices,
    // go right, or go upright and downright
    c1 = min(c1, c2 + c6);
    // similar for upright
    // go upright, or go upleft and right
    c2 = min(c2, c1 + c3);

    int ans = c1 * upright + c2 * right;
    cout << ans << endl;
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