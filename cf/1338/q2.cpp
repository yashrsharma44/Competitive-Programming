#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){

	ll n;
	cin>>n;

	vector<ll> a,b;
	ll nn = n;
	while(nn--){
		ll vl;
		cin>>vl;
		a.push_back(vl);
		b.push_back(vl);

	}

	sort(a.begin(),a.end());
	sort(b.begin(), b.end(), greater<ll>());

	vector < pair<ll,ll> > ans;

	if(n % 2 == 0){
		for(ll i=n/2;i<n;i++){
			ans.push_back(make_pair(a[i],b[i]));
		}
		
		for(auto el : ans){
			cout<<el.first<<" "<<el.second<<" ";
		}
		cout<<endl;		
	} else {
		for(ll i=(n-1)/2;i<n;i++){
			if(i == (n-1)/2){
				ans.push_back(make_pair(-1, b[i]));
			} else {
				ans.push_back(make_pair(a[i], b[i]));
			}
		}

		cout<<ans[0].second<<" ";
		for(ll i=1;i<ans.size();i++){
			cout<<ans[i].first<<" "<<ans[i].second<<" ";
		}
		cout<<endl;
	}



}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}
}