#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n; cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];

    vector<int> diff({0});
    for(int i=1;i<n;i++){
        if(a[i] > a[i-1]) diff.push_back(1);
        else diff.push_back(-1);
    }

    for(int i=1;i<n;i++){
        diff[i] += diff[i-1];
    }

    for(auto el : diff) cout<<el<<" ";
    cout<<endl;

    auto bs = [&](int end){

        int l = 0, r = end;
        // first True
        while(l < r){
            int m = (l + r) >> 1;
            int sum = diff[end] - diff[m-1];
            if(sum <=(end - m) && sum >= (end - m - 1)){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    };

    int ans = 0;
    for(int i=1;i<n;i++){
        // binary search from [0, i-1] all inclusive
        // which satisfies the condition pre[i] - pre[m-1]  <= (i - m)
        // and pre[i] - pre[m-1] >= (i - m - 1)

        int j = bs(i);
        if(j != -1){
            ans = max(ans, i - j + 2);
        }  
    }

    cout<<ans<<endl;
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