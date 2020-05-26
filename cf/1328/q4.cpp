#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> t(n,0);
	ll i=0;
	set<ll> elem;
	while(i<n){
		cin>>t[i++];
		elem.insert(t[i-1]);
	}

	if(elem.size() == 1){
		cout<<1<<endl;
		while(n--){
			cout<<1<<" ";
		}
		cout<<endl;
		return;
	}

	// If even the solve using 2 colors
	if(n % 2 == 0){

		ll clr=1;
		cout<<2<<endl;
		for(ll i=0;i<n;i++){
			cout<<clr<<" ";
			clr = (clr == 1) ? 2 : 1;
		}
		cout<<endl;
		return;
	} else {
		// If we find two elements which are same, the allot them
		// the same color and then the problem is reduced to a 
		// even cycle coloring

		bool isAdj = false;
		if(t[0] == t[n-1]){
			isAdj = true;
		}
		vector<ll> color(n,0);
		ll clr = 1;
		color[0]=1;
		for(ll i=1;i<n;i++){

			if(t[i] == t[i-1] && !isAdj){
				color[i]  = clr;
				isAdj = true;
				continue;
			} else {
				clr = (clr == 1) ? 2 : 1;
				color[i]  = clr;
			}
		}

		if(isAdj){
			cout<<2<<endl;
		} else {
			cout<<3<<endl;
			color[n-1] = 3;
		}

		for(ll el : color){

			cout<<el<<" ";

		}
		cout<<endl;
	}


}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}