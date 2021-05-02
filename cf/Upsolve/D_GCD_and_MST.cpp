#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;
// NICE PROBLEM, DIDNT THINK THAT WE CAN ITERATE VALUES BASED ON EDGE WEIGHTS
// NICE OBSERVATION :P

void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++) {
        arr.push_back({a[i], i});
    }

    sort(arr.begin(), arr.end());
    vector<bool> vis(n + 1, false);
    int mst = 0;

    for (auto edgeWeight : arr) {
        int el = edgeWeight[0], idx = edgeWeight[1];

        // if the node is already connected, lets skip it
        if (vis[idx]) continue;

        // if the min value is greater than p, we break out, because the rest of the edges can
        // be covered using p edge weight
        if (el >= p) break;

        // lets try to move left and right, while we know that el is going to be the minimum
        // and check if the adjacent elements have gcd == el. If not, we break out of that
        // connected component.
        int i = idx;
        while (i - 1 >= 0 && __gcd(el, a[i - 1]) == el && !vis[i - 1]) {
            vis[i - 1] = true;
            mst += el;
            i--;
        }

        i = idx;
        while (i + 1 < n && __gcd(el, a[i + 1]) == el && !vis[i]) {
            vis[i] = true;
            mst += el;
            i++;
        }
    }

    // cout << "VIS: " << endl;
    // for (int j = 0; j < n; j++) {
    //     cout << j << " " << vis[j] << endl;
    // }

    // add up the rest of the connected components using edge p
    for (int i = 0; i < n - 1; i++) {
        if (!vis[i]) mst += p;
    }

    cout << mst << endl;
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