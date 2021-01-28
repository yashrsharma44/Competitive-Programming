#include <bits/stdc++.h>
#define int long long 
#define MOD 100000000
using namespace std;

void solve(){

	int n; cin>>n;
	if(n%2 == 1){
		cout<<"YES"<<endl;
		return;
	}

	while(n%2==0){
		n/=2;
	}

	if(n == 1){
		cout<<"NO"<<endl;
		return;
	}
	cout<<"YES"<<endl;
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

