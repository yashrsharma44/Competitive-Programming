#include <bits/stdc++.h>
#define int long long

using namespace std;


void solve(){
    int p;
    cin>>p;
    int k = 1;
    vector<int> ans(p, 0);
    for(int i=0;i<p;i+=2){
        ans[i] = k++;
    }    
    if(p%2==0){
        for(int i=p-1;i>=0;i-=2){
            ans[i] = k++;
        }
    } else {
        for(int i=p-2;i>=0;i-=2){
            ans[i] = k++;
        }
    }
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
