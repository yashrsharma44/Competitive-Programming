#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){
	
	int l,r;
	cin>>l>>r;
	int ans = 2*l;
	if(ans <= r){
		cout<<l<<" "<<ans<<endl;
		return;
	}
	cout<<-1<<" "<<-1<<endl;
	
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
