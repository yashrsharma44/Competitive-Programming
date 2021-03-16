#include <bits/stdc++.h>
#define int long long
using namespace std;

int dp(vector<int> &b, vector<vector<int> > &arr, int i, int j) {
    int n = arr.size(), m = b.size();
    if (m == 0) return 0;
	
	int ans = 0;

    // two choice, put the val in box, or leave it
	for(int j=0;j<n;j++){

	}
	
    return ans;
}

bool comp(vector<int> &p1, vector<int> &p2) {
    return p1[1] > p2[1];
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int> > arr(n, vector<int>(2, 0));
    for (int i = 0; i < n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    sort(arr.begin(), arr.end(), comp);
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];
    vector<vector<int> > quer(q);
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // remove b[l:r+1]
        vector<int> bb;
        for (int i = 0; i < m; i++) {
            if (i + 1 >= l && i + 1 <= r) continue;
            bb.push_back(b[i]);
        }

        // prepare the optimum comb for max value
        vector<bool> vis(bb.size(), false);
        cout << dp(bb, arr, 0, vis) << endl;
    }
}

int32_t main() {
    int t;
    // cin>>t;
    t = 1;
    while (t--) {
        solve();
    }
}