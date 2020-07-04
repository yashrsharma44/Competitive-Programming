#include <bits/stdc++.h>
#define int long long 

using namespace std;

void solve(){

	int k,d;
	cin>>k>>d;
	if(d == 0){
		if(k == 1){
			cout<<0<<endl;
		} else {
			cout<<"No solution"<<endl;
		}
		// cout<<0<<endl;
		return;
	}

	string ans = to_string(d);
	for(int i=1;i<k;i++){
		ans +="0";
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
