#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,k;
	cin>>n>>k;
	
	if(n < k*k){
		cout<<"NO"<<endl;
		return;
	}

	if((n%2 == 0 && k%2==0) || (n%2==1 && k%2==1)){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}