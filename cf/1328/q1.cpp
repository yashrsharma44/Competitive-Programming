#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll a,b;
	cin>>a>>b;
	
	if(a%b == 0){
		cout<<0<<endl;
	} else {
		cout<<abs(b - (a % b))<<endl;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}