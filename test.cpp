#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll solve(int n, vector<int> D, vector<char> dir) {
    // sliding window, consider a valid subarray, and try taking a valid
    int cnt = 0;
    map<int, int> prevM;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L')
            ans -= D[i];
        else
            ans += D[i];
    }

    vector<int> pre({0});
    for (int i = 0; i < n; i++) {
        int el = D[i];
        if (dir[i] == 'L') {
            pre.push_back(pre.back() - el);

        } else {
            pre.push_back(pre.back() + el);
        }
    }

    vector<int> post(n + 1, 0);
    if (dir[n - 1] == 'L') {
        post[n - 1] = -D.back();

    } else {
        post[n - 1] = D.back();
    }
    for (int i = n - 2; i >= 0; i--) {
        if (dir[i] == 'L') {
            post[i] += post[i + 1] - D[i];
        } else {
            post[i] += post[i + 1] + D[i];
        }
    }
    auto prv = [&](vector<int> arr) {
        for (auto el : arr) {
            cout << el << " ";
        }
        cout << endl;
    };

    prv(pre);
    prv(post);
    prevM[0] = 0;

    for (int i = 0; i < n; i++) {
        if (dir[i] == 'L')
            cnt--;
        else
            cnt++;

        if (prevM.count(cnt) > 0) {
            // we can use a prevM occurance and take the post and pre sum
            int l_idx = prevM[cnt];

            ans = max(ans, pre[l_idx + 1] + post[i]);
            // update the cnt if the prev sum is greater
            if (pre[i] > pre[l_idx]) {
                prevM[cnt] = i;
            }
        } else {
            prevM[cnt] = i;
        }
    }

    return ans;
}

ll solver(int n, vector<int> D, vector<char> dir) {
    vector<char> rev;
    for (auto el : dir) {
        if (el == 'L') {
            rev.push_back('R');
        } else {
            rev.push_back('L');
        }
    }

    ll ans = max(solve(n, D, dir), solve(n, D, rev));
    return ans;
}

int main() {
    auto ans = solver(5, {2, 3, 4, 1, 5}, {'L', 'R', 'L', 'R', 'L'});
    cout << ans;
    cout << endl;
}

string getResult(int n, int m, int k, int x, string word, vector<string> clue) {
    for (auto &it : clue) sort(it.begin(), it.end());

    string poss;
    reverse(clue.begin(), clue.end());
    for (auto it : clue) poss += it[0];

    ll curr = 1, i;
    vector<ll> tot(m, 1);

    for (int i = 0; i < m; i++) {
        tot[i] = curr;
        if (x < curr) break;

        curr *= clue[i].size();
    }
    return poss;
}

string word;
vector<string> clue;

clue.resize(noOfClue);