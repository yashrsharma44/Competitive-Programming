#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll n;
	cin>>n;

	ll nn = n;

	vector< vector <ll> > arr;

	for(ll i=0;i<n;i++){

		ll m;
		cin>>m;
		vector<ll> add;
		for(ll j=0;j<m;j++){
			ll vl;
			cin>>vl;
			add.push_back(vl);
		}
		arr.push_back(add);
	}

	// Lets find the non-increasing sequence
	vector< pair< ll,ll > > non_inc;

	for(vector<ll> pr : arr){

		ll isNonInc = true;
		for(ll i=0;i<pr.size()-1;i++){

			if(pr[i] < pr[i+1]){
				isNonInc = false;
				break;
			}

		}

		if(isNonInc){
			non_inc.push_back(make_pair(pr[pr.size()-1], pr[0]));
		}

	}

	ll ans = (n * n);

	sort(non_inc.begin(), non_inc.end());

	for(ll i=0;i<non_inc.size();i++){

		ans -= (non_inc.end() - lower_bound(non_inc.begin(), non_inc.end(), make_pair(non_inc[i].second, (ll)-1)));

	}

	cout<<ans<<endl;
	return 0;
}