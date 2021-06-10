#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MOD = 998244353;

// bitmap stores the data of N people in chunks of 32 values
// Each value represents 32 people's values, so we can perform
// 'and' operation among N people in O(N / 32) operations
// 'count' operation also works in O(N / 32) time complexity
// Really clever optimization :D - https://codeforces.com/contest/1523/submission/117911694
struct bitmap {
    //    public:
    vector<unsigned int> container;
    int N;
    int Q;

    // fill to prefill the container with fill value
    bitmap(int n, int fill) {
        N = n;
        Q = (N + 31) / 32;
        container.assign(Q, fill);
        if (N % 32 != 0) {
            container.back() &= (1 << (N % 32)) - 1;
        }
        // cout << name << " " << container.back() << endl;
    }

    int insert(int x) {
        // cout << "------" << endl;
        // cout << x << " " << container[x / 32] << endl;
        container[x / 32] |= (1 << (x & 31));
        // cout << container[x / 32] << endl;
        // cout << "------" << endl;
    }

    int count() {
        int ans = 0;
        for (int i = 0; i < Q; i++) {
            ans += __builtin_popcount(container[i]);
        }
        return ans;
    }

    void print() {
        for (int i = 0; i < Q; i++) {
            cout << container[i] << " ";
        }
        cout << endl;
    }
};

bitmap AND(bitmap &p1, bitmap &p2) {
    int Q = p1.Q;
    bitmap ans(p1.N, 0);
    for (int i = 0; i < Q; i++) {
        ans.container[i] = p1.container[i] & p2.container[i];
    }
    return ans;
}

void solve() {
    // srand(time(0));
    int n, m, p;
    cin >> n >> m >> p;
    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int quorum = (n + 1) / 2;
    int maxCount = 0;
    vector<int> ans(m, 0);

    for (int iter = 0; iter < 20; iter++) {
        // choose a random index
        int idx = (0 + rand()) % n;
        // idx = 2;
        // cout << "Index: " << idx << endl;

        vector<int> choice;
        for (int i = 0; i < m; i++) {
            if (a[idx][i] == '1') choice.push_back(i);
        }

        // cout << "choice:" << idx << endl;
        // for (int el : choice) cout << el << " ";
        // cout << endl;

        // compress all the index of other friends
        vector<int> rem;
        int sz = choice.size();

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int z = 0; z < sz; z++) {
                int j = choice[z];
                if (a[i][j] == '1') cnt = cnt | (1 << z);
            }
            rem.push_back(cnt);
        }
        // cout << "rem:" << endl;
        // for (auto el : rem) cout << el << " ";
        // cout << endl;

        // consider all the submasks of current choice
        // and add the count
        vector<int> count(1 << sz, 0);
        for (int i = 0; i < n; i++) {
            count[rem[i]]++;
        }

        // cout << "count:" << endl;
        // for (int i = 0; i < (1 << sz); i++) cout << i << " " << count[i] << endl;
        // cout << endl;

        // construct the prefix sum
        // a submask is a sum of all possible supermask
        // SOS DP!

        // iterate over all the subsets of the mask
        for (int i = 0; i < sz; i++) {
            for (int mask = 0; mask < (1 << sz); mask++) {
                if (mask & (1 << i)) {
                    count[mask - (1 << i)] += count[mask];
                }
            }
        }

        // cout << "prefix:" << endl;
        // for (int i = 0; i < (1 << sz); i++) cout << i << " " << count[i] << endl;
        // cout << endl;

        bool change = false;
        for (int i = 0; i < (1 << sz); i++) {
            if (count[i] >= quorum) {
                if (__builtin_popcount(i) > __builtin_popcount(maxCount)) {
                    maxCount = i;
                    change = true;
                }
            }
        }

        if (change) {
            // update the answer
            vector<int> res(m, 0);
            for (int i = 0; i < sz; i++) {
                int j = choice[i];
                if (maxCount & (1 << i)) {
                    res[j] = 1;
                }
            }
            ans = res;
        }
    }

    for (int el : ans) cout << el;
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // cout.tie(NULL);

    int t;
    // cin >> t;
    t = 1;

    while (t--) {
        solve();
    }
}