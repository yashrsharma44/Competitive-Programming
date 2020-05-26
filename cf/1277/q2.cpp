#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll n;
	cin>>n;
	ll ctr=0;
	// vector< pair<ll,ll> > a;
	set<ll, greater<ll> > nums;
	// map<ll,ll> mp;
	ll nn = n;

	// priority_queue<ll, set<ll> > q;
	
	while(nn--){
		ll vl;
		cin>>vl;
		// mp[vl] = vl;
		
		// a.push_back(make_pair(a,ctr++));
		// if(nums.find(vl)==nums.end()){
			if(vl % 2 == 0){
				// q.push(vl);
				nums.insert(vl);
			}	
		// }
	}

	ll count = 0;

	while(nums.size()!=0){

		auto el = nums.begin();
		
		if((*el / 2) % 2 == 0){
			nums.insert(*el/2);
		}
		count++;
		nums.erase(*el);
	}

	cout<<count<<endl;

}

int main(){

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}