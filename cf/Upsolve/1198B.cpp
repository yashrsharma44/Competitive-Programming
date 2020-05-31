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
	
	ll q;
	cin>>q;
	vector<ll> v[q];
	vector<ll> last(n,-1);
	for(ll i=0;i<q;i++){

		ll op;
		cin>>op;
		v[i].push_back(op);
		if(op == 1){
			ll p,x;
			cin>>p>>x;
			p--;
			last[p] = i;
			v[i].push_back(p);
			v[i].push_back(x);
		} else {
			ll x;
			cin>>x;
			v[i].push_back(x);
		}
	}

	vector<ll> suffixMax(q+1, 0);
	for(ll i=q-1;i>=0;i--){
		if(v[i][0] == 2){
			suffixMax[i] = v[i][1]; 
		}
		suffixMax[i] = max(suffixMax[i], suffixMax[i+1]);
	}

	vector<ll> ans(a);
	for(ll i=0;i<n;i++){

		if(last[i] == -1){
			ans[i] = max(a[i], suffixMax[0]);
		} else {
			ans[i] = max(v[last[i]][2], suffixMax[last[i] + 1]);
		}
	}

	for(ll el : ans){
		cout<<el<<" ";
	}
	cout<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	// cin>>t;
	t = 1;

	while(t--){
		solve();
	}
}
