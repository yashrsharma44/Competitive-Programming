#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
    int xa, ya;
    cin >> xa >> ya;
    int xb, yb;
    cin >> xb >> yb;
    int xf, yf;
    cin >> xf >> yf;

    int dist = abs(xa - xb) + abs(ya - yb);

    // check collinear
    if ((xa == xb && xb == xf && (min(ya, yb) <= yf && yf <= max(ya, yb))) || (ya == yb && yb == yf && (min(xa, xb) <= xf && xf <= max(xa, xb)))) {
        dist += 2;
    }
    cout << dist << endl;
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