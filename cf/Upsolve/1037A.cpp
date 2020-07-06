#include <bits/stdc++.h>
#define int long long

using namespace std;


void solve(){
    
    int n;
    cin>>n;
    
    int k = 1;
    int count = 0;
    while(n>0){
        count++;
        n-=k;
        k*=2;
    }
    cout<<count<<endl;

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
