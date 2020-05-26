#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m,k;
	cin>>n>>m>>k;

	vector<ll> a;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	// remove k min elements greedily
	for(ll i=0;i<min(k,m-1);i++){

		if(a[0] < a[a.size() - 1]){
			a.erase(a.begin()+0);
		} else {
			a.erase(a.begin() + a.size() - 1);
		}

	}

	if(k > m-1){

		cout<<max(a[0], a[a.size()-1])<<endl;
		return;

	}


	// Now remove m - k max elements greedily
	for(ll i=0;i<(m-k-1);i++){

		if(a[0] > a[a.size() - 1]){
			a.erase(a.begin()+0);
		} else {
			a.erase(a.begin() + a.size() - 1);
		}

	}

	// for(ll el : a){
	// 	cout<<el<<" ";
	// }
	// cout<<endl;


	cout<<max(a[0], a[a.size()-1])<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}