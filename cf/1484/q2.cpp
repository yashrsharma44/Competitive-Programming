#include <bits/stdc++.h>
#define int long long
#define MOD 100000000
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    set<int> less;
    set<int> grt;
    int mx = a[0];
    for(int i=1;i<n;i++){
        if(a[i] >= a[i-1]) less.insert(a[i] - a[i-1]);
        else grt.insert(a[i-1] - a[i]);
        mx = max(mx, a[i]);
    }

    if(less.size() > 1 || grt.size() > 1){
        // multiple values of c, not possible
        cout<<-1<<endl;
        return;
    }

    if(less.size() == 0 || grt.size() == 0){
        // no c possible
        // arbit val of m possible
        cout<<0<<endl;
        return;
    }
    
    int n1 = *less.begin(), n2 = *grt.begin();
    if(n1+n2 < mx){
        cout<<-1<<endl;
        return;
    }
    cout<<n1+n2<<" "<<n1<<endl;


}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    // t = 1;

    while (t--) {
        solve();
    }
}