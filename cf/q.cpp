#include <bits/stdc++.h>
using namespace std;
#define ll long long

int solve(vector<int> B, int x, int N) {
    vector<int> A(N + 1, 0);
    for (int i = 0; i < N; i++) {
        A[i + 1] = B[i];
    }
    vector<vector<int>> prev(N + 2, vector<int>(N + 2, 0));
    for (int i = 0; i <= N + 1; i++) {
        prev[i][] = i;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (prev[i][j] == 1) {
                prev[i][j + 1] = N;
            } else {
                prev[i][j + 1] = prev[i][j] - 1;
            }
        }
    }

    vector<vector<int>> cost(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; i++) {
        cost[i][0] = A[i];
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            cost[i][j + 1] = min(cost[i][j], A[prev[i][j + 1]]);
        }
    }

    int ans = INT_MAX;
    for (int t = 0; t <= N; t++) {
        int sm = 0;
        for (int i = 1; i <= N; i++) {
            sm += cost[i][t];
        }

        ans = min(ans, sm + t * x);
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    auto ans = solve({50, 1, 50}, 5, 3);
    cout << ans << endl;
    return 0;
}
