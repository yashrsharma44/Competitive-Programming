#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

clock_t time_p = clock();

void checkTime() {
    time_p = clock() - time_p;
    cerr << "Time elapsed : " << (float)(time_p) / CLOCKS_PER_SEC * 1000 << "ms\n";
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> inp(n);
    for (int i = 0; i < n; i++) cin >> inp[i];
    int count = 0;
    vector<bool> vis(m, false);

    for (int c = 0; c < m; c++) {
        for (int r = 1; r < n; r++) {
            if (inp[r][c] >= inp[r - 1][c]) continue;
            // lets find a column from 0 -> c-1 and check if there exists one column with inp[r][k] < inp[r-1][k]
            bool check = true;
            for (int k = 0; k < c; k++) {
                if (!vis[k] && inp[r][k] > inp[r - 1][k]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                count += 1;
                vis[c] = true;
                break;
            }
        }
    }
    cout << count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while (t--) {
        solve();
    }
    checkTime();
}