#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

class DSU {
   public:
    vector<int> par;
    vector<int> rnk;
    int N;
    DSU(int n) {
        par = vector<int>(n, -1);
        for (int i = 0; i < n; i++) {
            par[i] = i;
        }
        rnk = vector<int>(n, 0);
        N = n;
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    bool Union(int x, int y) {
        int xr = find(x), yr = find(y);
        if (xr == yr) {
            return false;
        }
        if (rnk[xr] < rnk[yr]) {
            swap(xr, yr);
        }
        if (rnk[xr] == rnk[yr]) {
            rnk[xr] += 1;
        }
        par[yr] = xr;
        return true;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    // among all available pos, binary search for the nearest
    // position, and choose that
    // GREEDY :P

    vector<int> empty;
    vector<int> fill;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1)
            fill.push_back(i);
        else
            empty.push_back(i);
    }
    int MAX = 1e9;
    int N = fill.size(), M = empty.size();

    vector<vector<int>> cache(N, vector<int>(M, -1));
    function<int(int, int)> dp = [&](int i, int j) {
        if (i == N) return 0LL;

        if (j == M) return MAX;

        if (cache[i][j] != -1) return cache[i][j];
        // for i take j
        int ans = dp(i + 1, j + 1) + abs(fill[i] - empty[j]);

        // dont take j
        ans = min(ans, dp(i, j + 1));
        return cache[i][j] = ans;
    };

    int ans = dp(0, 0);
    // cout << "   |";
    // for (int i = 0; i < M; i++) {
    //     cout << i << " ";
    // }
    // cout << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << dp(i, j) << " \n"[j == M - 1];
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