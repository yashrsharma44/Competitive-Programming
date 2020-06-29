#include <bits/stdc++.h>
#define int long long

using namespace std;

void solve(){

	int n;
	cin>>n;

	if(n == 3){
		cout<<"NO"<<endl;
		return;
	}

	if((n / 4) * 4 == n){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
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
