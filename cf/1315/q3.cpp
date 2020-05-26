#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> b;
	ll nn = n;
	
	set<ll> elem;
	for(ll i=1;i<=2*n;i++){
		elem.insert(i);
	}

	map<ll,ll> res;
	vector<ll> a;
	vector<ll> aa;
	while(nn--){
		ll vl;
		cin>>vl;
		res[vl] = 0;
		aa.push_back(vl);
		a.push_back(vl);
		elem.erase(vl);
	}

	for(ll el : elem){
		b.push_back(el);
	}

	sort(b.begin(), b.end());
	// sort(a.begin(), a.end(), greater<ll>());

	vector<ll> ans(2*n, 0);

	ll i=0;
	bool isPos = true;
	for(ll el : a){

		for(ll i=0;i<b.size();i++){
			if(elem.find(b[i])!=elem.end() && b[i] > el){
				res[el] = b[i];
				elem.erase(b[i]);
				break;
			}
		}
		
	}

	if(elem.size()!=0){
		isPos = false;
	}

	if(!isPos){
		cout<<-1<<endl;
	} else {
		for(ll el : aa){
			cout<<el<<" "<<res[el]<<" ";
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