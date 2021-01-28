#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	if(n%2020 == 0 || n %2021 == 0){
		cout<<"YES"<<endl;
		return;	
	}
	for(int i=0;i<=500;i++){
		int val = n - i*2020;
		if(val < 0) break;

		if(val % 2021 == 0){
			cout<<"YES"<<endl;
			return;
		}
	}

	cout<<"NO"<<endl;
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

