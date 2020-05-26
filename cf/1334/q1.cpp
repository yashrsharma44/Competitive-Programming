#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void solve(){
	
	ll  n;
	cin>>n;

	vector <pair<ll,ll> > ans;
	ll nn = n;
	while(nn--){
		ll u,v;
		cin>>u>>v;
		ans.push_back(make_pair(u,v));
	}

	if(n == 1){
		if(ans[0].first < ans[0].second){
			cout<<"NO"<<endl;
		} else {
			cout<<"YES"<<endl;
		}
		return;
	}



	int dp = 0, dc = 0;
	bool isPos = true;
	
	if(ans[0].first < ans[0].second){
		isPos = false;
	}

	for(ll i=1;i<ans.size();i++){

		dp = ans[i].first - ans[i-1].first;
		dc = ans[i].second - ans[i-1].second;

		if(dp < 0 || dc < 0 || (dp < dc || ans[i].first < ans[i].second)){
			isPos = false;
			break;
		}
	}

	if(isPos){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}

int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	ll t;
	cin>>t;

	while(t--){
		solve();
	}

}	

