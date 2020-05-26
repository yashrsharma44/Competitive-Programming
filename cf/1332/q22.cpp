#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
		
	ll n;
	cin>>n;

	ll nn = n;
	vector<ll> a;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
	}

	map< ll,ll >mp;
	vector < vector<ll> > anss;
	vector<ll> visited(2000, false);
	ll nums[] = {2,3,5,7,11,13,17,19,23,29,31,37,41};
	ll color = 1;
	for(ll num : nums){

		vector<ll> ans;
		for(ll el : a){

			if(!visited[el] && (el % num == 0)){
				ans.push_back(el);
				visited[el] = true;
				mp[el]= color;
			}
		}
		if(ans.size()!=0){
			anss.push_back(ans);
			color++;
		}
	}

	cout<<color-1<<endl;
	for(ll el : a){
		cout<<mp[el]<<" ";
	}
	cout<<endl;

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