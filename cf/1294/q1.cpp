#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll a,b,c,n;
	cin>>a>>b>>c>>n;

	ll total = n + (a+b+c);

	if(total % 3 == 0){
		// cout<<"YES"<<endl;
		ll k = total / 3;
		bool isPos = true;

		if(k - a < 0){
			isPos = false;
		} 

		if(k - b < 0){
			isPos = false;
		}

		if(k - c < 0){
			isPos = false;
		}

		if(isPos){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}

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