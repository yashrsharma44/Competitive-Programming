#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll x,y;
	cin>>x>>y;

	if(y <= x){
		cout<<"YES"<<endl;
	} else {

		if(x == 3 || x == 1 || (x == 2 && y!=3)){
			cout<<"NO"<<endl;
			return;
		}

		if(x == 2 && y == 3){
			cout<<"YES"<<endl;
			return;
		}

		cout<<"YES"<<endl;

	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}