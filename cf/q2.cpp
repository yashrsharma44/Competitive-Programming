#include <bits/stdc++.h>
#define int long long
using namespace std;

vector<int> solve(int n, vector<int> arrTime, vector<int> direction) {
    int curr = 0;
    vector<vector<int>> entry, exit;
    for (int i = 0; i < n; i++) {
        if (direction[i] == 1)
            exit.push_back({arrTime[i], i});
        else
            entry.push_back({arrTime[i], i});
    }

    reverse(entry.begin(), entry.end());
    reverse(exit.begin(), exit.end());

    int last = -1;
    vector<int> ans(n, -1);
    for (int i = 0; i < n; i++) {
        if (arrTime[i] >= curr - 1) {
            // if prev is exit
            if (last == 1) {
                // consume exit
                if (exit.size() > 0) {
                    ans[exit.back()[1]] = curr;
                    last = 1;
                    curr += 1;
                    exit.pop_back();
                } else if (entry.size() > 0) {
                    ans[entry.back()[1]] = curr;
                    last = 0;
                    curr += 1;
                    entry.pop_back();
                }
            } else {
                if (entry.size() > 0) {
                    ans[entry.back()[1]] = curr;
                    last = 0;
                    curr += 1;
                    entry.pop_back();
                } else if (exit.size() > 0) {
                    ans[exit.back()[1]] = curr;
                    last = 1;
                    curr += 1;
                    exit.pop_back();
                }
            }

        } else {
            // consume exit if present
            if (exit.size() > 0) {
                ans[exit.back()[1]] = curr;
                last = 1;
                curr += 1;
                exit.pop_back();
            } else if (entry.size() > 0) {
                ans[entry.back()[1]] = curr;
                last = 0;
                curr += 1;
                entry.pop_back();
            }
        }
    }

    return ans;
}

int32_t main() {
    auto ans = solve(4, {0, 0, 1, 5}, {0, 1, 1, 0});
    for (auto el : ans) {
        cout << el << " ";
    }
    cout << endl;
}