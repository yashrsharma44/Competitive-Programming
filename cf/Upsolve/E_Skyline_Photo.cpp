#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> h(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    // normal dp solution:
    // dp(i) = max(dp(j) + min(b[j..i])) for all 0<=j<i

    // we can optimise our search space by considering two things -
    // dp(i) depends on j such that h[j] < h[i]. We can be sure that
    // the best answer would be stored at dp(j)

    // Once we have this invariant, we need to store max elements from dp(j)..dp(i-1)
    // and our answer; dp(i) = max(dp(j)...dp(i-1)) + b[i]

    // since b[i] is the smallest building till k>=j+1, so we can be sure that b[i] is the beauty
    // and then choose the max dp in that range

    // Lets use a monotonic stack, where we would maintain a increasing sequence of numbers
    // and we would try to get next lesser element to i to its left, and store all the max values till j+1
    int INF = 1e18;
    stack<int> st({0});
    h[0] = -INF;
    vector<int> dp(n + 1, 0);
    vector<int> maxx(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        // pop elements if stack element > h[i]
        // we want to maintain an increasing stack

        // stack always contains atleast 1 element, so no need to check if stack is empty
        int mx = -INF;
        while (h[st.top()] > h[i]) {
            mx = max(mx, maxx[st.top()]);
            st.pop();
        }

        maxx[st.top()] = max(maxx[st.top()], mx);
        dp[i] = maxx[st.top()] + b[i];

        // if we have a smaller element to i, on its left
        if (st.top() != 0) {
            dp[i] = max(dp[i], dp[st.top()]);
        }
        st.push(i);

        maxx[i] = dp[i];
    }

    cout << dp[n] << endl;
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