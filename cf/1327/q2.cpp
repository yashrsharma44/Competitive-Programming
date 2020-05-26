#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;
	ll nn = n;
	vector< vector<ll> > daug;

	while(nn--){

		ll k;
		cin>>k;
		vector<ll> entry;
		while(k--){
			ll vl;
			cin>>vl;
			entry.push_back(vl);
		}
		daug.push_back(entry);
	}

	set<ll> containsPrince;
	set<ll> unmarriedDaug;
	for(ll i=1;i<=n;i++){
		containsPrince.insert(i);
		unmarriedDaug.insert(i);
	}

	pair<ll,ll> ans = make_pair(-1,-1);

	for(ll i=0;i<n;i++){

		for(ll j=0;j<daug[i].size();j++){

			if(containsPrince.find(daug[i][j])!=containsPrince.end()){
				containsPrince.erase(daug[i][j]);
				unmarriedDaug.erase(i+1);
				break;
			}
		}
	}

	if(unmarriedDaug.size() == 0){
		cout<<"OPTIMAL"<<endl;
	} else {
		for(ll el : unmarriedDaug){
			for(ll el2 : containsPrince){
				// cout<<el<<" "<<el2<<endl;
				ans.first = el;
				ans.second = el2;
				break;
			}
			if(ans.first!=-1){
				break;
			}
		}

		cout<<"IMPROVE"<<endl;
		cout<<ans.first<<" "<<ans.second<<endl;
	}
}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}