#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	ll n;
	cin>>n;

	ll count = 0;
	ll b = 0;
	for(ll i=1;i<=9;i++){

		b = b * 10 + 1;
		for(ll j=1;j<=9;j++){
			if(b*j <= n){
				count++;
			}
		}
	}

	cout<<count<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}