#include <bits/stdc++.h>
#define ll long long int

using namespace std;

void dfs(vector<ll> local, vector<vector<ll> > &choices, ll ptr, vector<ll> cmp){

	if(ptr == local.size()){
		choices.push_back(cmp);
		return;
	}
	for(ll i=0;i<local.size();i++){
		ll val = local[ptr] * local[i];
		if(val > 100000){
			return;
		}
		cmp.push_back(val);
		dfs(local, choices, ptr+1, cmp);
		cmp.erase(cmp.begin()+cmp.size()-1);
	}

}

void solve(){

	ll n;
	cin>>n;
	ll nn=n;

	vector<ll> arr;
	while(nn--){
		ll vl;
		cin>>vl;
		arr.push_back(vl);
	}

	vector < ll > dp(n+1, 0);
	vector<ll> choice;
	choice.push_back(1);
	choice.push_back(2);
	choice.push_back(3);
	choice.push_back(5);
	choice.push_back(7);
	choice.push_back(11);
	choice.push_back(13);
	choice.push_back(17);
	choice.push_back(19);

	for(ll i=1;i<=n;i++){

		ll mx = 0;
		for(ll el=1;el<=(ll)(sqrt(n) + 1);el++){
			if(i % el == 0 && arr[(i/el) - 1] < arr[i-1]){
				mx = max(mx, dp[i/el]);
			}
		}
		dp[i] = 1+mx;
	}

	ll ans =-1;
	for(ll el : dp){
		ans = max(el, ans);
	}
	cout<<ans<<endl;
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll t;
	cin>>t;
	// t = 1;

	while(t--){
		solve();
	}
}
