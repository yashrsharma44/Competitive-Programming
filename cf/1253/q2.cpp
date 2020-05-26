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

	set<ll> contains;
	set<ll> visited;
	vector<ll> res;
	ll ctr=0;

	bool isPos = true;

	// Lets keep two set, one for keeping a track whether they have been visited
	// and other for checking whther they have been removed 

	for(ll el : a){



		if(el > 0){
			
			if(visited.find(el)!=visited.end()){
				isPos = false;
				break;
			} else {
				contains.insert(el);
				visited.insert(el);
			}
		} else {

			if(contains.find(-el)!=contains.end()){
				contains.erase(-el);
			} else {
				isPos=false;
				break;
			}
		}
		ctr++;

		if(contains.size()==0){
			res.push_back(ctr);
			ctr=0;
			set<ll> visi;
			visited = visi;
		}

	}

	if(contains.size()!=0){
		isPos=false;
	}

	if(isPos){
		// res.push_back(ctr);
		cout<<res.size()<<endl;
		for(ll el : res){
			cout<<el<<" ";
		}
		cout<<endl;
	} else {
		cout<<-1<<endl;
	}
}

int main(){

	ll t;
	// cin>>t;
	t=1;
	while(t--){
		solve();
	}

}