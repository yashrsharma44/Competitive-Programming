#include <bits/stdc++.h>
#define int long long
#define MOD 100000007
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b(n);
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            b[i] = 1;
        } else if (a[i] < a[i - 1]) {
            b[i] = -1;
        } else {
            b[i] = 0;
        }
    }
    if (n > 1)
        b[0] = b[1];

    for(int i=0;i<m;i++){
        int l, r; cin>>l>>r;l--;r--;
        if(b[l] > 0 && b[r] > 0){
            cout<<"YES"
        }
    }
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