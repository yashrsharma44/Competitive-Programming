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

	vector < vector<ll> > nums;
	vector<bool> visited(2000, false);
	while(a.size()!=0){

		vector<ll> ans;
		// ll nm = a[0];
		ll nm = -1;
		for(ll i=0;i<n;i++){
			if(!visited[a[i]]){
				nm = a[i];
				visited[a[i]]=true;
				break;
			}
		}

		if(nm == -1){
			break;
		}

		ans.push_back(nm);
		for(ll i=0;i<n;i++){
			if(!visited[a[i]] && __gcd(nm, a[i])>1){
				
				bool isPos = true;
				for(ll el : ans){

					if(__gcd(a[i], el) == 1){
						isPos = false;
						break;
					}
				}
				if(isPos){
				ans.push_back(a[i]);
				visited[a[i]] = true;
	
				}	
			}
		}
		nums.push_back(ans);
	}

	// cout<<"YAY"<<endl;
	ll ctr=1;
	ll maxColor = 1;
	map<ll,ll> mp;
	for(vector<ll> par : nums){

		for(ll el : par){
			mp[el] = ctr;
		}
		maxColor = max(maxColor, ctr);
		ctr+=1;
	}

	cout<<maxColor<<endl;
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