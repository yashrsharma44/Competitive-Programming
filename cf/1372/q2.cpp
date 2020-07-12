#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){
    
    int n;
    cin>>n;
    if(n%2 == 0){
    	cout<<n/2<<" "<<n/2<<endl;
    	return;
    }
    if(n == 3){
    	cout<<1<<" "<<2<<endl;
    	return;
    }

    int start = 1;
    for(int i=1;i*i<=n;i++){
    	if(n%(i+1) == 0){
    		start = n / (i+1);
    		break;
    	}
    }
    cout<<start<<" "<<(n-start)<<endl;
}


int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin>>t;
    // t = 1;

    while(t--){
        solve();
    }
}
