#include <bits/stdc++.h>
#define ll long long int

using namespace std;

vector<ll> getIntersection(vector<ll> a1, vector<ll> a2){

	vector<ll> ans;
	for(ll i=0;i<a1.size();i++){

		for(ll j=0;j<a2.size();j++){
			if(a1[i] == a2[j]){
				ans.push_back(a1[i]);
			}
		}

	}

	return ans;

}

void solve(){

	ll n;
	cin>>n;

	string s;
	cin>>s;

	vector < pair<ll,ll> > inp;
	ll nn = n;
	while(nn--){
		ll u,v;
		cin>>u>>v;

		inp.push_back(make_pair(u,v));
	}

	vector < vector<ll> > nums;
	for(ll i=0;i<n;i++){

		vector<ll> num;
		ll start = s[i] == '0' ? 1 : 0;
		for(ll j=inp[i].first + (start * inp[i].second); j<=50;j+=inp[i].second){
			num.push_back(j);
		}

		nums.push_back(num);
	}

	vector<ll> local(nums[0]);
	ll count=0;
	for(ll i=1;i<n;i++){

		local = getIntersection(local, nums[i]);

	}

	cout<<local.size()<<endl;

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