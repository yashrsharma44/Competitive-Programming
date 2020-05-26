#include <bits/stdc++.h>
#define ll long long int

using namespace std;

int main(){

	ll n;
	cin>>n;

	vector<ll> a,b;

	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		b.push_back(vl);
	}

	vector<ll> c(n,0);
	for(ll i=0;i<n;i++){
		c[i] = a[i] - b[i];
	}

	sort(c.begin(), c.end());

	ll totalCount = 0;
	for(ll i=0;i<n;i++){

		ll el = (-c[i] + 1);
		if(c[i] <= 0){
			continue;
		}
		ll idx = lower_bound(c.begin(), c.end(), el) - c.begin();
		// cout<<el<<"->"<<idx<<endl;
		totalCount += (i - idx);
	}

	cout<<totalCount<<endl;

}