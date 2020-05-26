#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll x;
	cin>>x;

	if(x % 2 == 0){
		cout<<(x/2)<<" "<<(x/2)<<endl;
	} else {
		cout<<(x-1)<<" "<<1<<endl;
	}

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}