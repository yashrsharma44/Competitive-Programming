#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> arr;

	ll nn = n;
	bool containEven = false;
	while(nn--){
		ll vl;
		cin>>vl;

		if(vl % 2 == 0){
			containEven = true;
		}
		arr.push_back(vl);
	}

	vector<ll> ans;
	if(containEven){

		for(ll i=0;i<n;i++){
			if(arr[i] % 2 == 0){
				cout<<1<<endl;
				cout<<(i+1)<<endl;
				return;
			}
		}

	} else {

		if(n == 1){
			cout<<-1<<endl;
			return;
		}
		cout<<2<<endl;
		cout<<1<<"  "<<2<<endl;
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