#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,x;
	cin>>n>>x;

	vector<ll> a;
	ll nn = n;
	
	// set<ll> cont;
	// for(ll i=1;i<=200;i++){
	// 	cont.insert(i);
	// }

	vector<ll> elem(200,0);
	ll maxEl = -1;
	while(nn--){
		ll vl;
		cin>>vl;
		maxEl = max(maxEl, vl);
		// cont.erase(vl);
		a.push_back(vl);
		elem[vl]=1;
	}

	ll itr=0;

	for(ll i=1;i<=200 && itr < x;i++){

		if(elem[i] == 0){
			elem[i] = 1;
			itr++;
		}
	}

	ll maxPos = 0;
	for(ll i=1;i<=200;i++){

		if(elem[i] == 0){
			break;
		}
		maxPos = i;
	}

	cout<<maxPos<<endl;
}

int main(){


	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}