#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n,m;
	cin>>n>>m;

	vector<ll> l;
	ll mm = m;
	// ll sumL = 0;
	set<ll, greater<ll> > nums;
	while(mm--){
		ll vl;
		cin>>vl;
		nums.insert(vl);
		
		l.push_back(vl);
	}

	// Possible if all distinct nums sum up to n
	ll sumL=0;

	for(ll el : nums){
		sumL+=el;
	}

	if(sumL < n){
		cout<<-1<<endl;
		return;
	}

	map<ll,ll> mp;

	ll pos=1;

	for(ll el : nums){
		mp[el] = pos;
		pos+=el;
	}

	vector <ll> ans(m, 1);

	for(ll i=0;i<m;i++){

		if(mp.find(l[i]) != mp.end()){
			ans[i] = mp[l[i]];
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
	
	ll t;
	// cin>>t;
	t=1;

	while(t--){
		solve();
	}

}