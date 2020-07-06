#include <bits/stdc++.h>
#define int long long 

using namespace std;


void solve(){

    int n,k;
    cin>>n>>k;
    if(n == k){
        cout<<-1<<endl;
        return;
    }
    // if(n == 1){
    //     if(k == 1)
    //     cout<<-1<<endl;
    //     else
    //     cout<<1<<endl;
    //     return;
    // }

    vector<int> ans(n,0);
    
    int cp = k;
    for(int i = n;i>=0&&k>0;i--){
        ans[i-1] = i;
        k--;
    }
    for(int i=0;i<n-cp-1;i++){
        ans[i] = i+2;
    }
    ans[n-cp-1] = 1;
    for(int el : ans){
        cout<<el<<" ";
    }
    cout<<endl;
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    // cin>>t;
    t = 1;

    while(t--){
        solve();
    }
}
