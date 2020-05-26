#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector < pair<ll,ll> > edge;
	ll mm = m;

	while(mm--){
		ll u,v;
		cin>>u>>v;

		edge.push_back(make_pair(u,v));
	}

	ll countDomino = 0;
	bool isSeven = false;
	for(pair<ll,ll> el : edge){

		if(el.first == 7 || el.second == 7){
			isSeven = true;
		} else {
			countDomino += 1;
		}
	}

	if(isSeven){
		cout<<countDomino+1<<endl;
	} else {
		cout<<countDomino<<endl;
	}
	
}

int main(){

	ll t;
	// cin>>t;
	t = 1;
	while(t--){
		solve();
	}
}