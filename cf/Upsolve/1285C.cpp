#include<bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll X;
	cin>>X;

	ll minVal = 10000000000000;
	// cout<<minVal<<endl;
	// cout<<"P"<<endl;
	for(ll i=1;i*i<=X;i++){

		// cout<<i<<" "<<X/i<<endl;
		// cout<<__gcd(i, X/i)<<endl;
		if(X % i ==0 && __gcd(i, X/i) == 1){

			minVal = min(minVal, max(i, X/i));
			// cout<<i<<" "<<(X / i)<<endl;
		}

	}

	cout<<(X / minVal)<<" "<<minVal<<endl;
}

int main(){

	solve();
}