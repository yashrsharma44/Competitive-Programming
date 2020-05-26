#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	ll nn = n;
	vector<ll> a;

	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	bool allEven = true;
	bool allOdd = true;

	for(ll i=0;i<n;i++){

		ll el = a[i];
		if(el % 2 == 0){
			allOdd = false;
		} else {
			allEven = false;
		}

	}

	if(allEven){

		cout<<"NO"<<endl;
		return;

	} 

	if(allOdd){

		ll sum = 0;
		for(ll i=0;i<n;i++){
			sum += a[i];
		}

		if(sum % 2 == 1){
			cout<<"YES"<<endl;
		} else {
			cout<<"NO"<<endl;
		}
		return;

	}

	// Some even some odd

	cout<<"YES"<<endl;
	return;
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}