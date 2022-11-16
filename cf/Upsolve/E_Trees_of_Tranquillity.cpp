#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> g[n + 1], og[n + 1];
    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        g[u].push_back(i);
        // g[i].push_back(u);
    }

    for (int i = 2; i <= n; i++) {
        int u;
        cin >> u;
        og[u].push_back(i);
        // og[i].push_back(u);
    }

    // for each node in og, calculate the ancestor of a node u
    vector<int> tin(n + 1, 0), tout(n + 1, 0);
    int time = 0;

    function<void(int)> dfs_time = [&](int node) {
        tin[node] = time++;
        for (auto nei : og[node]) {
            dfs_time(nei);
        }
        tout[node] = time;
    };

    dfs_time(1);

    set<pair<int, int>> intervals;

    // check if the {tin[node], tout[node]} intersects, and does not
    // lie inside an element of a intervals set.
    auto lies_inside = [&](pair<int, int> &x) -> bool {
        if (intervals.size() == 0) return true;
        auto it = intervals.lower_bound(x);

        if (it == intervals.end()) return true;
        return it->second > x.second;
    };

    // find the segment which intersects with the {tin[node], tout[node]}
    auto inside = [&](pair<int, int> &x) -> pair<int, int> {
        if (intervals.size() == 0) return {-1, -1};

        // last True
        auto it = intervals.upper_bound(x);
        if (it == intervals.begin()) return {-1, -1};
        it = prev(it);

        if (it->second >= x.second) return *it;
        return {-1, -1};
    };

    auto is_leaf = [&](int node) -> bool {
        if (node == 1) return false;
        if (g[node].size() == 0) return true;
        return false;
    };

    // For the condition,
    // u is an ancestor v or v is an ancestor of u,
    // iff both the nodes lie in a path from root(1) to a leaf

    // Lets consider a path from root(1) to a leaf, and see if
    // we can have the max sized disjoint set of intervals.

    // If the segments of {tin[u], tout[u]} is disjoint, we can
    // say that niether of the other segments is an ancestor of the
    // other segments. THIS IS AN IMPORTANT OBSERVATION!!!!!

    // We can use a set to store greedily, the max number of segments
    // which are disjoint with each other.

    // The entries of {tin[u], tout[u]} are inherently disjoint, so -
    // if the new segment intersects with an old segment,
    // you just need to remove a old segment,  Otherwise, if the new segment
    // lies inside an old segment. you dont add the new segment

    // so lets calculate the max size set.
    int ans = 0;
    function<void(int)> dfs = [&](int node) {
        pair<int, int> new_segment = {tin[node], tout[node]};
        pair<int, int> old_segment = {-1, -1};

        // check if new segment lies inside old segment
        bool added = false;
        if (lies_inside(new_segment)) {
            added = true;
            old_segment = inside(new_segment);

            if (old_segment.first != -1) {
                intervals.erase(old_segment);
            }
            intervals.insert(new_segment);
        }

        // update answer if leaf
        if (is_leaf(node)) {
            ans = max(ans, (int)(intervals.size()));
        }

        for (auto nei : g[node]) {
            dfs(nei);
        }

        // undo the changes for next dfs round
        if (added) {
            intervals.erase(new_segment);
        }
        if (old_segment.first != -1) {
            intervals.insert(old_segment);
        }
    };

    dfs(1);

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