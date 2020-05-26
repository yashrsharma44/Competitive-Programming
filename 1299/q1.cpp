#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> arr;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	ll steps = 0;

	// Check if zero
	// ll zeroInd = -1;
	for(ll i=0;i<n;i++){

		if(arr[i] == 0){
			arr[i] += 1;
			steps += 1;
		}

	}

	// Check if sum is zero
	ll sum = 0;
	for(ll i=0;i<n;i++){
		sum += arr[i];
	}

	if(sum == 0){

		ll maxEl = -1;
		for(ll i=0;i<n;i++){
			maxEl = max(maxEl, arr[i]);
		}

		if(maxEl > 0){
			steps += 1;
		} else {
			steps += (abs(maxEl) - 0 + 1);
		}

		cout<<steps<<endl;
		return;

	} else {
		cout<<steps<<endl;
		return;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}