#include <bits/stdc++.h>
#define ll long long int
using namespace std;

bool check(ll n){

	unordered_set<ll> num;
	while(n!=0){
			
		if(num.find(n%10)!=num.end()){
			return false;
		}
		num.insert(n%10);
		n = n / 10;
	}

	return true;
}

void solve(){


	ll l ,r;
	cin>>l>>r;

	for(ll i=l;i<=r;i++){

		if(check(i)){
			cout<<i<<endl;
			return;
		}
	}
	cout<<-1<<endl;
	return;
}

int main(){

	ll t = 1;
	// cin>>t;
	while(t--){
		solve();
	}
}