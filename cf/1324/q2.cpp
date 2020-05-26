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

	bool isPos = false;

	for(ll i=0;i<n;i++){

		vector<ll> diff(n,0);

		set<ll> mp;
		for(ll j=0;j<n;j++){

			if(j < i){
				mp.insert(arr[j]);
				
			} else if(j == i){
				continue;
			} else {
			
				if(mp.find(arr[j]) != mp.end()){
					isPos = true;
					break;
				}
			}

		}
	}

	if(isPos){
		cout<<"YES"<<endl;
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