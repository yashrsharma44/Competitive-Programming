#include <bits/stdc++.h>
#define int long long
int MOD = (int)1e9 + 7;

using namespace std;

void solve() {
    int n, l, r;
    int cost = 0;
    cin >> n >> l >> r;
    vector<int> left(l), right(r);
    for (int i = 0; i < l; i++) cin >> left[i];

    for (int i = 0; i < r; i++) cin >> right[i];

    // match common left with right
    // left is small
    vector<int> small, large;
    if (left.size() < right.size()) {
        small = left;
        large = right;
    } else {
        small = right;
        large = left;
    }

    multiset<int> ms(large.begin(), large.end());
    // try removing same color pair from left and right
    int i = 0;
    vector<int> leftOver;
    for (i = 0; i < small.size(); i++) {
        if (ms.count(small[i]) > 0) {
            ms.erase(ms.find(small[i]));
        } else {
            leftOver.push_back(small[i]);
        }
    }

    vector<int> rightOver(ms.begin(), ms.end());

    small = {};
    large = {};

    if (leftOver.size() < rightOver.size()) {
        small = leftOver;
        large = rightOver;
    } else {
        small = rightOver;
        large = leftOver;
    }
    // cout << "DBG: " << endl;
    // cout << "LeftOver:\n";
    // for (auto el : leftOver) cout << el << " ";
    // cout << endl;

    // cout << "rightOver:\n";
    // for (auto el : rightOver) cout << el << " ";
    // cout << endl;

    // Match small with large
    // choose element from large which has smallest count
    map<int, int> count;
    for (auto el : large) count[el]++;

    multiset<vector<int>> ms2;
    for (auto el : count) {
        ms2.insert({el.second, el.first});
    }

    // for (auto el : ms2) {
    //     cout << el[0] << " " << el[1] << endl;
    // }

    int rem = small.size();
    cost += rem;
    while (rem > 0) {
        auto top = *ms2.begin();
        ms2.erase(ms2.find(top));

        if (rem - top[0] > 0) {
            rem -= top[0];
        } else {
            top[0] -= rem;
            rem = 0;
            ms2.insert(top);
        }
    }
    // cout << endl;
    // for (auto el : ms2) {
    //     cout << el[0] << " " << el[1] << endl;
    // }

    vector<int> remaining;
    for (auto el : ms2) {
        int cnt = el[0];
        int elem = el[1];
        while (cnt > 0) {
            remaining.push_back(elem);
            cnt--;
        }
    }

    // cout << "Remaining" << endl;
    // for (auto el : remaining) cout << el << " ";
    // cout << endl;

    sort(remaining.begin(), remaining.end());

    // match remaining with similar colors
    int pup = 0;
    for (int i = 1; i < remaining.size();) {
        if (remaining[i - 1] == remaining[i]) {
            pup += 2;
            cost++;
            i += 2;
            continue;
        }
        i++;
    }

    rem = (remaining.size() - pup);
    assert(rem % 2 == 0);

    cost += rem;
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