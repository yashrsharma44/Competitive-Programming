#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int f(vector<vector<char>> board) {
    int n = (int)board.size(), m = (int)board[0].size();
    set<pair<int, int>> block;
    int mini = INT_MAX, minj = INT_MAX, maxi = INT_MIN, maxj = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == '*') {
                mini = min(mini, i);
                minj = min(minj, j);
                maxi = max(maxi, i);
                maxj = max(maxj, j);
                block.insert({i, j});
            }
        }
    }
    map<int, pair<int, int>> ma;
    for (auto &x : block) {
        if (ma.find(x.second - minj) == ma.end()) {
            ma[x.second - minj] = {x.first - mini, x.first - mini};
        } else {
            int ff = ma[x.second - minj].first, ss = ma[x.second - minj].second;
            ma[x.second - minj] = {min(x.first - mini, ff), max(x.first - mini, ss)};
        }
    }
    int ans = INT_MAX;
    for (int ctr = 0; ctr + maxj < m; ctr++) {
        int tmp = 0;
        for (auto x : ma) {
            for (int i = 0; i < n - (maxi - x.second.second); i++) {
                if (board[i][x.first + ctr] == '#') tmp += 1;
            }
        }
        ans = min(ans, tmp);
    }
    return ans;
}
int main() {
    vector<vector<char>> v{{'*', '*', '*'}, {'#', '*', '*'}, {'*', '*', '.'}, {'.', '#', '#'}}, v1{{'*', '*'}, {'#', '#'}};
    cout << f(v1) << endl;
}