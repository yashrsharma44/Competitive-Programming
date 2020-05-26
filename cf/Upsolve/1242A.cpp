
#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	bool isP = true;
	// check prime
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			isP = false;
			break;
		}
	}

	if(isP){
		cout<<n<<endl;
		return;
	}

	ll bigF = -1;
	for(ll i=2;i<=min(1000000ll,n-1);i++){

		if(n%i==0){
			bigF = i;
			break;
		}
	}

	while(n%bigF==0){
		n/=bigF;
	}

	if(n!=1){
		cout<<1<<endl;
	} else {
		cout<<bigF<<endl;
	}

}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}
}