#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    int nm = max(n, m);
    set<vector<int>> triplets;
    for (int i = 0; i <= nm; i++) {
        for (int j = 0; j <= nm; j++) {
            for (int k = 0; k <= nm; k++) {
                if (i + j + k != 0 && i * i + j * j == k * k) {
                    triplets.insert({i, j, k});
                }
            }
        }
    }

    set<vector<int>> points;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i + j != 0)
                points.insert({i, j});
        }
    }

    while (true) {
        auto point = *points.begin();
        bool delP = false;
        for (auto trp : triplets) {
            int dl[2] = {-1, 1};
            vector<int> newP;

            for (int z1 = 0; z1 < 2; z1++) {
                for (int z2 = 0; z2 < 2; z2++) {
                    newP = {point[0] + (dl[z1] * trp[0]), point[1] + (dl[z2] * trp[1])};
                    if (points.count(newP) > 0) {
                        points.erase(newP);
                        delP = true;
                    }
                }
            }
        }
        if (!delP) break;
    }
    cout << points.size() << endl;
    for (auto point : points) {
        cout << point[0] << " " << point[1] << endl;
    }
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
}