#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main(){

	ll n,m,k;
	cin>>n>>m>>k;

	map<ll,ll> contains;

	ll nn = n;
	while(nn--){
		ll r,v;
		cin>>r>>v;

		if(contains.find(r)!=contains.end()){
			contains[r] = min(v, contains[r]);
		} else {
			contains[r]  = v;
		}
	}

	ll total = 0;
	for(pair<ll,ll> el : contains){

		if(total + el.second > k){
			continue;
		}
		total += el.second;
	}

	cout<<total<<endl;
}