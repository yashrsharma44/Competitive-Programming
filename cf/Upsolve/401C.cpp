#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;



void solve(){

    int n,m; cin>>n>>m;
    if(n == m+1 || m == n+1 || n == m){
        if(n == m){
            for(int i=0;i<n;i++){
                cout<<"1 ";
                cout<<"0 ";
            }
            // return;
        }

        if(n == m+1){
            cout<<"0 ";
            for(int i=0;i<m;i++){
                cout<<"1 0 ";
            }
            // return;
        }

        if(m == n+1){
            cout<<"1 ";
            for(int i=0;i<n;i++){
                cout<<"0 1 ";
            }
            // return;
        }

        return;
    } 
    
    // 11 0 11 0 
    if(m / 2 < n - 1)
    
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