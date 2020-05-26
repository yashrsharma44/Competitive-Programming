#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;
	
	if(k < n){
		cout<<k<<endl;
		return;
	}

	// ll val = k / (n-1);
	// ll rem = k % n;
	// if(rem==0){
	// 	cout<<(n*val)-1<<endl;
	// 	return;
	// }
	// cout<<(n*val)+rem<<endl;
	ll val = k / (n-1);
	ll rem = k % (n-1);
	if(rem == 0){
		rem = n-1;
		val = val - 1;
	}
	cout<<(val*n)+rem<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;

	

	while(t--){
		solve();
	}
}