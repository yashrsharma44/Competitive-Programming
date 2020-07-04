#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int k;
	cin>>k;
	if(k > 36){
		cout<<-1<<endl;
		return;
	}
	string ans = "";
	for(int i=0;i<k/2;i++){
		ans += "8";
	}
	if(k%2!=0){
		ans = "6" + ans;
	}	
	cout<<ans<<endl;
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
