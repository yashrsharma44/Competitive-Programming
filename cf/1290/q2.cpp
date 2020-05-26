#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);	
	}

	ll leftMax = -1;
	for(ll i=0;i<n;i++){

		if(a[i] >= (i)){
			// continue;
			leftMax = i;
		} else {
			// leftMax = i-1;
			break;
		}

	}

	ll rightMax = n;
	for(ll i=n-1;i>=0;i--){

		if(a[i] >= (n - i - 1)){
			// continue;
			rightMax = i;
		} else {
			// rightMax = i+1;
			break;
		}

	}

	if(leftMax >= rightMax){
		cout<<"Yes"<<endl;
	} else {
		cout<<"No"<<endl;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}
