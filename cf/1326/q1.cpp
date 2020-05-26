#include <bits/stdc++.h>
#define ll long long int

using namespace std;

bool check(ll n){

	ll nm = n;
	while(n>0){
		ll dig = n % 10;
		if((dig == 0) || nm % dig == 0){
			return false;
		}
		n /= 10;
	}

	return true;

}

void solve(){

	
	ll n;
	cin>>n;
	if(n==1){
		cout<<-1<<endl;
		return;
	}

	string ans="2";
	for(ll i=0;i<n-1;i++){
		ans+="3";
	}

	cout<<ans<<endl;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}