#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    vector<vector<int>> pieces;
    set<vector<int>> kill;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 'o') pieces.push_back({i, j});
            if (grid[i][j] == 'x') kill.insert({i, j});
        }
    }

    // find all the o's and do a possible
    // path search, if all x's are covered,
    // it is a possible solution

    vector<vector<int>> horse({{-2, -1}, {2, -1}, {-1, -2}, {1, -2}, {-2, 1}, {2, 1}, {-1, 2}, {1, 2}});
    // elephant moves up and down, left and right
    vector<vector<int>> camel({{-1, -1}, {-1, 1}, {1, -1}, {1, 1}});
    vector<vector<int>> soldier({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
    vector<int> king({-1, 0, -1});
    // queen moves like king with full diagonals

    auto valid = [&](int r, int c) {
        return (r >= 0 && r < n && c >= 0 && c < n);
    };

    auto check = [&](int id, set<vector<int>> killed) {
        if (id == 0) {
            // horse
            for (auto piece : pieces) {
                for (auto dir : horse) {
                    int rr = piece[0] + dir[0];
                    int cc = piece[1] + dir[1];

                    if (valid(rr, cc)) {
                        killed.erase({rr, cc});
                    }
                }
            }
        }

        if (id == 1) {
            // elephant
            for (auto piece : pieces) {
                for (auto dir : soldier) {
                    int rr = piece[0];
                    int cc = piece[1];

                    for (int k = 1; valid(rr, cc); k++) {
                        rr += dir[0];
                        cc += dir[1];

                        killed.erase({rr, cc});
                    }
                }
            }
        }

        if (id == 2) {
            // camel
            for (auto piece : pieces) {
                for (auto dir : camel) {
                    int rr = piece[0];
                    int cc = piece[1];

                    for (int k = 1; valid(rr, cc); k++) {
                        rr += dir[0];
                        cc += dir[1];

                        killed.erase({rr, cc});
                    }
                }
            }
        }

        if (id == 3) {
            // soldier
            for (auto piece : pieces) {
                for (auto dir : soldier) {
                    int rr = piece[0] + dir[0];
                    int cc = piece[1] + dir[1];

                    if (valid(rr, cc)) killed.erase({rr, cc});
                }
            }
        }

        if (id == 4) {
            // king
            for (auto piece : pieces) {
                for (auto dr : king) {
                    for (auto dc : king) {
                        int rr = piece[0] + dr;
                        int cc = piece[1] + dc;

                        if (valid(rr, cc)) killed.erase({rr, cc});
                    }
                }
            }
        }

        if (id == 5) {
            // queen
            for (auto piece : pieces) {
                for (auto dr : king) {
                    for (auto dc : king) {
                        int rr = piece[0];
                        int cc = piece[1];
                        for (int k = 1; valid(rr, cc); k++) {
                            rr += dr;
                            cc += dc;
                            if (valid(rr, cc)) killed.erase({rr, cc});
                        }
                    }
                }
            }
        }

        return killed.size() == 0;
    };
    vector<vector<char>> ans(2 * n - 1, vector<char>(2 * n - 1, '.'));

    auto genPieces = [&](int id) {
        int r = n - 1, c = n - 1;
        ans[r][c] = 'o';
        if (id == 0) {
            // horse
            for (auto dir : horse) {
                int rr = r + dir[0];
                int cc = c + dir[1];

                if (valid(rr, cc)) ans[rr][cc] = 'x';
            }
        }

        if (id == 1) {
            // elephant
            for (auto dir : soldier) {
                int rr = r;
                int cc = c;
                for (int k = 1; valid(rr, cc); k++) {
                    rr += dir[0];
                    cc += dir[1];
                    if (valid(rr, cc)) ans[rr][cc] = 'x';
                }
            }
        }

        if (id == 2) {
            // camel
            for (auto dir : camel) {
                int rr = r;
                int cc = c;
                for (int k = 1; valid(rr, cc); k++) {
                    rr += dir[0];
                    cc += dir[1];
                    if (valid(rr, cc)) ans[rr][cc] = 'x';
                }
            }
        }

        if (id == 3) {
            // soldier
            for (auto dir : soldier) {
                int rr = r + dir[0];
                int cc = c + dir[1];
                if (valid(rr, cc)) ans[rr][cc] = 'x';
            }
        }

        if (id == 4) {
            // king
            for (auto dr : king) {
                for (auto dc : king) {
                    int rr = r + dr;
                    int cc = c + dc;

                    if (valid(rr, cc)) ans[rr][cc] = 'x';
                }
            }
        }
        if (id == 5) {
            // queen
            for (auto dr : king) {
                for (auto dc : king) {
                    int rr = r;
                    int cc = c;

                    for (int k = 1; valid(rr, cc); k++) {
                        rr += dr;
                        cc += dc;
                        if (valid(rr, cc)) ans[rr][cc] = 'x';
                    }
                }
            }
        }
        for (auto el : ans) {
            for (auto e : el) {
                cout << e;
            }
            cout << endl;
        }
        return;
    };

    // check for horse
    if (check(0, kill)) {
        cout << "YES" << endl;
        genPieces(0);
        return;
    }

    // check for elephant
    if (check(1, kill)) {
        cout << "YES" << endl;
        genPieces(1);
        return;
    }

    // check for camel
    if (check(2, kill)) {
        cout << "YES" << endl;
        genPieces(2);
        return;
    }

    // check for soldier
    if (check(3, kill)) {
        cout << "YES" << endl;
        genPieces(3);
        return;
    }

    // check for king
    if (check(4, kill)) {
        cout << "YES" << endl;
        genPieces(4);
        return;
    }

    // check for queen
    if (check(5, kill)) {
        cout << "YES" << endl;
        genPieces(5);
        return;
    }

    cout << "NO" << endl;
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