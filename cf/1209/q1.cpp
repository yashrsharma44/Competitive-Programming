#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a;
	// set<ll> ss;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		// ss.insert(vl);
		a.push_back(vl);
	}

	ll count=0;

	while(a.size()!=0){

		sort(a.begin(), a.end());
		ll minEl = a[0];
		
		auto itr3 = find(a.begin(), a.end(), minEl);
		a.erase(itr3);		
		
		ll itr=0;
		vector<ll> elems;
		while(itr<a.size()){
			if(a[itr] % minEl == 0){
				elems.push_back(a[itr]);
			}
			itr++;
		}

		// itr=0;
		// ll i=0;

		while(elems.size()!=0){

			auto itr2 = find(a.begin(), a.end(), elems[0]);
			a.erase(itr2);
			elems.erase(elems.begin());
		}
		count++;
	}

	cout<<count<<endl;

}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}
}